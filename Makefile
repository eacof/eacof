.PHONY: clean all lib libca libconsumer libprovider liball cleanExecutables cleanArchives cleanObjectFiles tests testsca testsconsumer testsprovider

# compiler settings
CC = gcc
POSIX_VERSION=-D_POSIX_C_SOURCE=200809L
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O2
LIBS = -ldl -lpthread
ifeq ($(OS),Windows_NT)
    # not supported
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        EXAMPLES_FRAMEWORK =
    endif
    ifeq ($(UNAME_S),Darwin)
        EXAMPLES_FRAMEWORK = -framework IntelPowerGadget
    endif
endif

# folders and output files
DOCS_DIR = docs
DOXYGEN_DIR = $(DOCS_DIR)/doxygen
HEADERS_DIR_NAME = headers
LIB_DIR_NAME = lib
CA_DIR_NAME = ca
CONSUMER_DIR_NAME = consumer
PROVIDER_DIR_NAME = provider
CA_DIR = $(LIB_DIR_NAME)/$(CA_DIR_NAME)
CONSUMER_DIR = $(LIB_DIR_NAME)/$(CONSUMER_DIR_NAME)
DUMMY_DIR = $(LIB_DIR_NAME)/dummy
PROVIDER_DIR = $(LIB_DIR_NAME)/$(PROVIDER_DIR_NAME)
SHARED_DIR = $(LIB_DIR_NAME)/shared

DEVICE_GEN_SCRIPT = codegen/devices/device_gen.py

EACOF_LIB_NAME = eacof
EACOF_LIB_FILENAME = lib$(EACOF_LIB_NAME).a

EXAMPLES_DIR_NAME = examples
EXAMPLES_DIR_CA = $(EXAMPLES_DIR_NAME)/$(CA_DIR_NAME)
EXAMPLES_DIR_CONSUMER = $(EXAMPLES_DIR_NAME)/$(CONSUMER_DIR_NAME)
EXAMPLES_DIR_PROVIDER = $(EXAMPLES_DIR_NAME)/$(PROVIDER_DIR_NAME)

# header files
EACOF_HEADERS = $(wildcard $(HEADERS_DIR_NAME)/*.h)

# C source files
EACOF_LIB_SRC_CA = $(wildcard $(CA_DIR)/*.c)
EACOF_LIB_SRC_CONSUMER = $(wildcard $(CONSUMER_DIR)/*.c)
EACOF_LIB_SRC_DUMMY = $(wildcard $(DUMMY_DIR)/*.c)
EACOF_LIB_SRC_PROVIDER = $(wildcard $(PROVIDER_DIR)/*.c)
EACOF_LIB_SRC_SHARED = $(wildcard $(SHARED_DIR)/*.c)
EACOF_LIB_SRC = $(EACOF_LIB_SRC_CA) $(EACOF_LIB_SRC_CONSUMER) $(EACOF_LIB_SRC_PROVIDER) $(EACOF_LIB_SRC_SHARED)

# compiled object files
EACOF_LIB_OBJ_CA = $(EACOF_LIB_SRC_CA:.c=.o)
EACOF_LIB_OBJ_CONSUMER = $(EACOF_LIB_SRC_CONSUMER:.c=.o)
EACOF_LIB_OBJ_DUMMY = $(EACOF_LIB_SRC_DUMMY:.c=.o)
EACOF_LIB_OBJ_PROVIDER = $(EACOF_LIB_SRC_PROVIDER:.c=.o)
EACOF_LIB_OBJ_SHARED = $(EACOF_LIB_SRC_SHARED:.c=.o)
# NOTE: This 'all' value must not contain the DUMMY values
EACOF_LIB_OBJ = $(EACOF_LIB_OBJ_CA) $(EACOF_LIB_OBJ_CONSUMER) $(EACOF_LIB_OBJ_PROVIDER) $(EACOF_LIB_OBJ_SHARED)

# object archives
EACOF_LIB_AR_CA = $(CA_DIR)/$(EACOF_LIB_FILENAME)
EACOF_LIB_AR_CONSUMER = $(CONSUMER_DIR)/$(EACOF_LIB_FILENAME)
EACOF_LIB_AR_PROVIDER = $(PROVIDER_DIR)/$(EACOF_LIB_FILENAME)
EACOF_LIB_AR = $(LIB_DIR_NAME)/$(EACOF_LIB_FILENAME)

# example files
EACOF_EXAMPLE_SRC_CA = $(wildcard $(EXAMPLES_DIR_CA)/*.c)
EACOF_EXAMPLE_SRC_CONSUMER = $(wildcard $(EXAMPLES_DIR_CONSUMER)/*.c)
EACOF_EXAMPLE_SRC_PROVIDER = $(wildcard $(EXAMPLES_DIR_PROVIDER)/*.c)
EACOF_EXAMPLE_OBJ_CA = $(EACOF_EXAMPLE_SRC_CA:.c=.o)
EACOF_EXAMPLE_OBJ_CONSUMER = $(EACOF_EXAMPLE_SRC_CONSUMER:.c=.o)
EACOF_EXAMPLE_OBJ_PROVIDER = $(EACOF_EXAMPLE_SRC_PROVIDER:.c=.o)
EACOF_EXAMPLE_SRC = $(wildcard $(EXAMPLES_DIR)/*.c)
EACOF_EXAMPLE_OBJ = $(EACOF_EXAMPLE_SRC:.c=.o)

# docs
EACOF_DOCS_FILES = $(wildcard $(DOCS_DIR)/*.md)

# creating everything
all: deviceGen lib examples

# creating the examples
# example programs are individual c files and are one of CA, Consumer, Provider
examples: examplesca examplesconsumer examplesprovider

examplesca: $(EACOF_EXAMPLE_OBJ_CA) $(EACOF_LIB_AR_CA)

examplesconsumer: $(EACOF_EXAMPLE_OBJ_CONSUMER) $(EACOF_LIB_AR_CONSUMER)

examplesprovider: $(EACOF_EXAMPLE_OBJ_PROVIDER) $(EACOF_LIB_AR_PROVIDER)

# compile the source into an object file, then link into a binary
# the messy syntax is so that linking is done against the correct lib and the output file is right
$(EXAMPLES_DIR_NAME)/%.o: $(EXAMPLES_DIR_NAME)/%.c $(EACOF_HEADERS)
	$(CC) $(CFLAGS) $(POSIX_VERSION) -I$(HEADERS_DIR_NAME) -c $< -o $@
	$(CC) $(CFLAGS) $(POSIX_VERSION) $(patsubst %.c,%.o,$(firstword $^)) -L$(LIB_DIR_NAME)/$(word 2,$(subst /, ,$(firstword $^))) -l$(EACOF_LIB_NAME) $(LIBS) $(EXAMPLES_FRAMEWORK) -o $(firstword $(patsubst %.c,%,$^))

# creating the library archives
lib: libca libconsumer libprovider liball

libca: $(EACOF_LIB_OBJ_CA) $(EACOF_LIB_OBJ_SHARED)
	ar -rcs $(EACOF_LIB_AR_CA) $(EACOF_LIB_OBJ_CA) $(EACOF_LIB_OBJ_SHARED)

libconsumer: $(EACOF_LIB_OBJ_CONSUMER) $(EACOF_LIB_OBJ_SHARED) $(EACOF_LIB_OBJ_DUMMY)
	ar -rcs $(EACOF_LIB_AR_CONSUMER) $(EACOF_LIB_OBJ_CONSUMER) $(EACOF_LIB_OBJ_SHARED) $(EACOF_LIB_OBJ_DUMMY)

libprovider: $(EACOF_LIB_OBJ_PROVIDER) $(EACOF_LIB_OBJ_SHARED) $(EACOF_LIB_OBJ_DUMMY)
	ar -rcs $(EACOF_LIB_AR_PROVIDER) $(EACOF_LIB_OBJ_PROVIDER) $(EACOF_LIB_OBJ_SHARED) $(EACOF_LIB_OBJ_DUMMY)

liball: $(EACOF_LIB_OBJ)
	ar -rcs $(EACOF_LIB_AR) $(EACOF_LIB_OBJ)

# sqlite won't compile with the POSIX flag set
$(CA_DIR)/sqlite3.o: $(CA_DIR)/sqlite3.c $(EACOF_HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR_NAME) -c $< -o $@
# object files
%.o: %.c $(EACOF_HEADERS)
	$(CC) $(CFLAGS) $(POSIX_VERSION) -I$(HEADERS_DIR_NAME) -c $< -o $@

# clean things up
clean: cleanExecutables cleanObjectFiles cleanArchives

cleanExecutables:
	find . -name \*exampleProgram -type f -delete
	find . -name \*Example -type f -delete

cleanObjectFiles:
	find . -name \*.o -type f -delete
#	find . ! -name sqlite3.o -name \*.o -type f -delete

cleanArchives:
	find . -name \*.a -type f -delete

deviceGen:
	./$(DEVICE_GEN_SCRIPT)

docs: $(EACOF_HEADERS) $(EACOF_LIB_SRC) $(EACOF_DOCS_FILES)
	doxygen doxygen.conf
