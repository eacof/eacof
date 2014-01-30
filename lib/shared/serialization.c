/**
    @file

    @brief Code to serialize and deserialize data sent across the network.

    This allows data to be sent in a manner that may be understood by those at either end of the channel of communication.
*/
#include <eacof/serialization.h>

/**
    Serialize a single value with a given bit width
    This currently uses a very naive memcpy method
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @param bytes The number of bytes that the value is.

    @pre buf must contain at least `bytes` bytes of free space
    @post buf is incremented by `bytes`
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_value(eacof_nettype *buf, void *value, uint8_t bytes) {
    unsigned char* pValue = (unsigned char*)value;

    for(uint8_t currByte = 0; currByte < bytes; currByte++) {
        *buf++ = *pValue++;
    }

    return buf;
}

/**
    Deserialize a single value with a given bit width
    This currently uses a very naive memcpy method

    @param[in] value Value to be serialized
    @param[out] buf A pointer to the output buffer
    @param bytes The number of bytes that the value is.

    @pre buf must contain at least `bytes` bytes of free space
    @post buf is incremented by `bytes`
    @warning buffer overflow may occur if bytes pushes over the end of buf
*/
eacof_nettype *eacof_deserialize_value(void *value, eacof_nettype *buf, uint8_t bytes) {
    unsigned char* pValue = (unsigned char*)value;

    for(uint8_t currByte = 0; currByte < bytes; currByte++) {
        *pValue++ = *buf++;
    }

    return buf;
}

/**
    Serialize a single int16_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 2 bytes of free space
    @post buf is incremented by 2
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_int16(eacof_nettype *buf, int16_t value) {
    return eacof_serialize_value(buf, &value, sizeof(int16_t));
}

/**
    Deserialize a single int16_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 2 bytes in the buffer are the results of a call to eacof_serialize_int16()
    @post The value now contains a 16 bit representation of the input buffer. buf is incremented by 2
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_int16(eacof_nettype *buf, int16_t *value) {
    return eacof_deserialize_value(value, buf, sizeof(int16_t));
}

/**
    Serialize a single uint16_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 2 bytes of free space
    @post buf is incremented by 2
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_uint16(eacof_nettype *buf, uint16_t value) {
    value = htons(value);
    return eacof_serialize_value(buf, &value, sizeof(uint16_t));
}

/**
    Deserialize a single uint16_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 2 bytes in the buffer are the results of a call to eacof_serialize_uint16()
    @post The value now contains a 16 bit representation of the input buffer. buf is incremented by 2
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_uint16(eacof_nettype *buf, uint16_t *value) {
    buf = eacof_deserialize_value(value, buf, sizeof(uint16_t));
    *value = ntohs(*value);
    return buf;
}

/**
    Serialize a single int32_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 4 bytes of free space
    @post buf is incremented by 4
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_int32(eacof_nettype *buf, int32_t value) {
    return eacof_serialize_value(buf, &value, sizeof(int32_t));
}

/**
    Deserialize a single int32_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 4 bytes in the buffer are the results of a call to eacof_serialize_int32()
    @post The value now contains a 32 bit representation of the input buffer. buf is incremented by 4
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_int32(eacof_nettype *buf, int32_t *value) {
    return eacof_deserialize_value(value, buf, sizeof(int32_t));
}

/**
    Serialize a single uint32_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 4 bytes of free space
    @post buf is incremented by 4
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_uint32(eacof_nettype *buf, uint32_t value) {
    value = htonl(value);
    return eacof_serialize_value(buf, &value, sizeof(uint32_t));
}

/**
    Deserialize a single uint32_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 4 bytes in the buffer are the results of a call to eacof_serialize_uint32()
    @post The value now contains a 32 bit representation of the input buffer. buf is incremented by 4
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_uint32(eacof_nettype *buf, uint32_t *value) {
    buf = eacof_deserialize_value(value, buf, sizeof(uint32_t));
    *value = ntohl(*value);
    return buf;
}

/**
    Serialize a single int64_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 8 bytes of free space
    @post buf is incremented by 8
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_int64(eacof_nettype *buf, int64_t value) {
    return eacof_serialize_value(buf, &value, sizeof(int64_t));
}

/**
    Deserialize a single int64_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 8 bytes in the buffer are the results of a call to eacof_serialize_int64()
    @post The value now contains a 64 bit representation of the input buffer. buf is incremented by 8
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_int64(eacof_nettype *buf, int64_t *value) {
    return eacof_deserialize_value(value, buf, sizeof(int64_t));
}

/**
    Serialize a single uint64_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 8 bytes of free space
    @post buf is incremented by 8
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_uint64(eacof_nettype *buf, uint64_t value) {
    return eacof_serialize_value(buf, &value, sizeof(uint64_t));
}

/**
    Deserialize a single uint64_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 8 bytes in the buffer are the results of a call to eacof_serialize_uint64()
    @post The value now contains a 64 bit representation of the input buffer. buf is incremented by 8
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_uint64(eacof_nettype *buf, uint64_t *value) {
    return eacof_deserialize_value(value, buf, sizeof(uint64_t));
}

/**
    Code to pack a floating point value in IEEE 754 format.
    Credit goes to: http://beej.us/guide/bgnet/examples/ieee754.c
    @param double f The value to pack
    @param unsigned bits The number of bits in the value
    @param unsigned expbits The number of bits in the exponent
    @warning Doesn't handle NaN or Infinity
    http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#serialization
*/
uint64_t eacof_pack754(double f, unsigned bits, unsigned expbits) {
    double fnorm;
    int shift;
    long long sign, exp, significand;
    unsigned significandbits = bits - expbits - 1; // -1 for sign bit

    if (f == 0.0) return 0; // get this special case out of the way

    // check sign and begin normalization
    if (f < 0) { sign = 1; fnorm = -f; }
    else { sign = 0; fnorm = f; }

    // get the normalized form of f and track the exponent
    shift = 0;
    while(fnorm >= 2.0) { fnorm /= 2.0; shift++; }
    while(fnorm < 1.0) { fnorm *= 2.0; shift--; }
    fnorm = fnorm - 1.0;

    // calculate the binary form (non-float) of the significand data
    significand = fnorm * ((1LL<<significandbits) + 0.5f);

    // get the biased exponent
    exp = shift + ((1<<(expbits-1)) - 1); // shift + bias

    // return the final answer
    return (sign<<(bits-1)) | (exp<<(bits-expbits-1)) | significand;
}

/**
    Code to unpack a floating point value in IEEE 754 format.
    Credit goes to: http://beej.us/guide/bgnet/examples/ieee754.c
    @param uint64_t i The value to unpack
    @param unsigned bits The number of bits in the value
    @param unsigned expbits The number of bits in the exponent
    @warning Doesn't handle NaN or Infinity
    http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#serialization
*/
double eacof_unpack754(uint64_t i, unsigned bits, unsigned expbits) {
    double result;
    long long shift;
    unsigned bias;
    unsigned significandbits = bits - expbits - 1; // -1 for sign bit

    if (i == 0) return 0.0;

    // pull the significand
    result = (i&((1LL<<significandbits)-1)); // mask
    result /= (1LL<<significandbits); // convert back to float
    result += 1.0f; // add the one back on

    // deal with the exponent
    bias = (1<<(expbits-1)) - 1;
    shift = ((i>>significandbits)&((1LL<<expbits)-1)) - bias;
    while(shift > 0) { result *= 2.0; shift--; }
    while(shift < 0) { result /= 2.0; shift++; }

    // sign it
    result *= (i>>(bits-1))&1? -1.0: 1.0;

    return result;
}

/**
    Pack a double into a bit pattern
    @param double i The bits to convert to a double
    @return An unpacked double
*/
uint64_t eacof_pack_double(double f) {
    return eacof_pack754(f, 64, 11);
}

/**
    Unpack a bit pattern into a double
    @param uint64_t i The bits to convert to a double
    @return An unpacked double
*/
double eacof_unpack_double(uint64_t i) {
    return eacof_unpack754(i, 64, 11);
}

/**
    Serialize a single double
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @pre buf must contain at least 8 bytes of free space
    @post buf is incremented by 8
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_double(eacof_nettype *buf, double value) {
    uint64_t byteVal;

    byteVal = eacof_pack_double(value);

    return eacof_serialize_uint64(buf, byteVal);
}

/**
    Deserialize a single double
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @pre The first 8 bytes in the buffer are the results of a call to eacof_serialize_double()
    @post The value now contains a 64 bit representation of the input buffer. buf is incremented by 8
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_double(eacof_nettype *buf, double *value) {
    uint64_t byteVal;

    buf = eacof_deserialize_uint64(buf, &byteVal);
    *value = eacof_unpack_double(byteVal);

    return buf;
}

/**
    Serialize a single bool
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_bool(eacof_nettype *buf, bool value) {
    uint16_t byteVal;

    byteVal = value ? 1 : 0;

    return eacof_serialize_uint16(buf, byteVal);
}

/**
    Deserialize a single bool
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_bool(eacof_nettype *buf, bool *value) {
    uint16_t byteVal;

    buf = eacof_deserialize_uint16(buf, &byteVal);
    *value = byteVal ? true : false;

    return buf;
}

/**
    Serialize a single pid_t
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_pid(eacof_nettype *buf, pid_t value) {
    // TODO: Ensure this is a valid datatype to use
    int64_t byteVal;

    byteVal = (int64_t)value;

    return eacof_serialize_int64(buf, byteVal);
}

/**
    Deserialize a single pid_t
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_pid(eacof_nettype *buf, pid_t *value) {
    int64_t byteVal;

    buf = eacof_deserialize_int64(buf, &byteVal);
    *value = (pid_t)byteVal;

    return buf;
}

/**
    Serialize a single Device
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_device(eacof_nettype *buf, eacof_Device value) {
    return eacof_serialize_value(buf, &value, sizeof(eacof_Device));
}

/**
    Deserialize a single DeviceCount
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_devicecount(eacof_nettype *buf, eacof_DeviceCount *value) {
    return eacof_deserialize_value(value, buf, sizeof(eacof_DeviceCount));
}

/**
    Serialize a single DeviceCount
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_devicecount(eacof_nettype *buf, eacof_DeviceCount value) {
    return eacof_serialize_value(buf, &value, sizeof(eacof_DeviceCount));
}

/**
    Deserialize a single Device
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_device(eacof_nettype *buf, eacof_Device *value) {
    return eacof_deserialize_value(value, buf, sizeof(eacof_Device));
}

/**
    Serialize a single ProbeID
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_probeid(eacof_nettype *buf, eacof_ProbeID value) {
    return eacof_serialize_value(buf, &value, sizeof(eacof_ProbeID));
}

/**
    Deserialize a single ProbeID
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_probeid(eacof_nettype *buf, eacof_ProbeID *value) {
    return eacof_deserialize_value(value, buf, sizeof(eacof_ProbeID));
}

/**
    Serialize a single CheckpointID
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_checkpointid(eacof_nettype *buf, eacof_CheckpointID value) {
    return eacof_serialize_value(buf, &value, sizeof(eacof_CheckpointID));
}

/**
    Deserialize a single CheckpointID
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_checkpointid(eacof_nettype *buf, eacof_CheckpointID *value) {
    return eacof_deserialize_value(value, buf, sizeof(eacof_CheckpointID));
}

/**
    Serialize a single ProcessSpecifier
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_processspecifier(eacof_nettype *buf, eacof_ProcessSpecifier value) {
    return eacof_serialize_int64(buf, value);
}

/**
    Deserialize a single ProcessSpecifier
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_processspecifier(eacof_nettype *buf, eacof_ProcessSpecifier *value) {
    return eacof_deserialize_int64(buf, value);
}

/**
    Serialize a single Probe
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_probe(eacof_nettype *buf, eacof_Probe value) {
    buf = eacof_serialize_probeid(buf, value.uid);
    buf = eacof_serialize_devicecount(buf, value.deviceCount);
    for(eacof_DeviceCount currDevice = 0; currDevice < value.deviceCount; currDevice++) {
        buf = eacof_serialize_device(buf, value.device[currDevice]);
    }
    buf = eacof_serialize_bool(buf, value.active);

    return buf;
}

/**
    Deserialize a single Probe
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_probe(eacof_nettype *buf, eacof_Probe *value) {
    buf = eacof_deserialize_probeid(buf, &(value->uid));
    buf = eacof_deserialize_devicecount(buf, &(value->deviceCount));
    // TODO: Handle failed malloc() and the resulting bubble up
    value->device = (eacof_Device *) malloc(value->deviceCount * sizeof(eacof_Device));
    for(eacof_DeviceCount currDevice = 0; currDevice < value->deviceCount; currDevice++) {
        buf = eacof_deserialize_device(buf, &(value->device[currDevice]));
    }
    buf = eacof_deserialize_bool(buf, &(value->active));

    return buf;
}

/**
    Serialize a single Checkpoint
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_checkpoint(eacof_nettype *buf, eacof_Checkpoint value) {
    buf = eacof_serialize_checkpointid(buf, value.uid);
    buf = eacof_serialize_devicecount(buf, value.deviceCount);
    for(eacof_DeviceCount currDevice = 0; currDevice < value.deviceCount; currDevice++) {
        buf = eacof_serialize_device(buf, value.device[currDevice]);
    }
    buf = eacof_serialize_processspecifier(buf, value.pspec);

    return buf;
}

/**
    Deserialize a single Checkpoint
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_checkpoint(eacof_nettype *buf, eacof_Checkpoint *value) {
    buf = eacof_deserialize_checkpointid(buf, &(value->uid));
    buf = eacof_deserialize_devicecount(buf, &(value->deviceCount));
    // TODO: Handle failed malloc() and the resulting bubble up
    value->device = (eacof_Device *) malloc(value->deviceCount * sizeof(eacof_Device));
    for(eacof_DeviceCount currDevice = 0; currDevice < value->deviceCount; currDevice++) {
        buf = eacof_deserialize_device(buf, &(value->device[currDevice]));
    }
    buf = eacof_deserialize_processspecifier(buf, &(value->pspec));

    return buf;
}

/**
    Serialize a single command
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_command(eacof_nettype *buf, eacof_Command value) {
    return eacof_serialize_uint16(buf, value);
}

/**
    Deserialize a single command
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_command(eacof_nettype *buf, eacof_Command *value) {
    return eacof_deserialize_uint16(buf, value);
}

/**
    Serialize a single sample
    @param[out] buf A pointer to the output buffer
    @param[in] value Value to be serialized
    @warning buffer overflow will occur if there is not enough free space
*/
eacof_nettype *eacof_serialize_sample(eacof_nettype *buf, eacof_Sample value) {
    return eacof_serialize_double(buf, value);
}

/**
    Deserialize a single sample
    @param[in] buf A pointer to the input buffer
    @param[out] value pointer to the output value
    @warning Will read past the end of the buffer if not enough space is allocated
*/
eacof_nettype *eacof_deserialize_sample(eacof_nettype *buf, eacof_Sample *value) {
    return eacof_deserialize_double(buf, value);
}
