#ifndef EACOF_SERIALIZATION_H
#define EACOF_SERIALIZATION_H
/**
    @file

    @brief A header for serialization and deserialization functions.
*/

#include <eacof/types.h>

#include <inttypes.h>
#include <stdlib.h>
#include <arpa/inet.h>

#ifdef __cplusplus
extern "C" {
#endif

eacof_nettype *eacof_serialize_value(eacof_nettype *buf, void *value, uint8_t bytes);
eacof_nettype *eacof_deserialize_value(void *value, eacof_nettype *buf, uint8_t bytes);

eacof_nettype *eacof_serialize_int16(eacof_nettype *buf, int16_t value);
eacof_nettype *eacof_deserialize_int16(eacof_nettype *buf, int16_t *value);
eacof_nettype *eacof_serialize_uint16(eacof_nettype *buf, uint16_t value);
eacof_nettype *eacof_deserialize_uint16(eacof_nettype *buf, uint16_t *value);

eacof_nettype *eacof_serialize_int32(eacof_nettype *buf, int32_t value);
eacof_nettype *eacof_deserialize_int32(eacof_nettype *buf, int32_t *value);
eacof_nettype *eacof_serialize_uint32(eacof_nettype *buf, uint32_t value);
eacof_nettype *eacof_deserialize_uint32(eacof_nettype *buf, uint32_t *value);

eacof_nettype *eacof_serialize_int64(eacof_nettype *buf, int64_t value);
eacof_nettype *eacof_deserialize_int64(eacof_nettype *buf, int64_t *value);
eacof_nettype *eacof_serialize_uint64(eacof_nettype *buf, uint64_t value);
eacof_nettype *eacof_deserialize_uint64(eacof_nettype *buf, uint64_t *value);

uint64_t eacof_pack754(double f, unsigned bits, unsigned expbits);
double eacof_unpack754(uint64_t i, unsigned bits, unsigned expbits);
uint64_t eacof_pack_double(double f);
double eacof_unpack_double(uint64_t i);
eacof_nettype *eacof_serialize_double(eacof_nettype *buf, double value);
eacof_nettype *eacof_deserialize_double(eacof_nettype *buf, double *value);

eacof_nettype *eacof_serialize_bool(eacof_nettype *buf, bool value);
eacof_nettype *eacof_deserialize_bool(eacof_nettype *buf, bool *value);

eacof_nettype *eacof_serialize_pid(eacof_nettype *buf, pid_t value);
eacof_nettype *eacof_deserialize_pid(eacof_nettype *buf, pid_t *value);

eacof_nettype *eacof_serialize_device(eacof_nettype *buf, eacof_Device value);
eacof_nettype *eacof_deserialize_device(eacof_nettype *buf, eacof_Device *value);

eacof_nettype *eacof_serialize_devicecount(eacof_nettype *buf, eacof_DeviceCount value);
eacof_nettype *eacof_deserialize_devicecount(eacof_nettype *buf, eacof_DeviceCount *value);

eacof_nettype *eacof_serialize_probeid(eacof_nettype *buf, eacof_ProbeID value);
eacof_nettype *eacof_deserialize_probeid(eacof_nettype *buf, eacof_ProbeID *value);

eacof_nettype *eacof_serialize_checkpointid(eacof_nettype *buf, eacof_CheckpointID value);
eacof_nettype *eacof_deserialize_checkpointid(eacof_nettype *buf, eacof_CheckpointID *value);

eacof_nettype *eacof_serialize_processspecifier(eacof_nettype *buf, eacof_ProcessSpecifier value);
eacof_nettype *eacof_deserialize_processspecifier(eacof_nettype *buf, eacof_ProcessSpecifier *value);

eacof_nettype *eacof_serialize_probe(eacof_nettype *buf, eacof_Probe value);
eacof_nettype *eacof_deserialize_probe(eacof_nettype *buf, eacof_Probe *value);

eacof_nettype *eacof_serialize_checkpoint(eacof_nettype *buf, eacof_Checkpoint value);
eacof_nettype *eacof_deserialize_checkpoint(eacof_nettype *buf, eacof_Checkpoint *value);

eacof_nettype *eacof_serialize_command(eacof_nettype *buf, eacof_Command value);
eacof_nettype *eacof_deserialize_command(eacof_nettype *buf, eacof_Command *value);

eacof_nettype *eacof_serialize_sample(eacof_nettype *buf, eacof_Sample value);
eacof_nettype *eacof_deserialize_sample(eacof_nettype *buf, eacof_Sample *value);

#ifdef __cplusplus
}
#endif

#endif // EACOF_SERIALIZATION_H
