/*
 * Copyright (C) 2017 Kubos Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @defgroup Types
 * @addtogroup Types
 * @brief Public telemetry types
 * @{
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <csp/csp.h>

/**
 * Telemetry union for storing data.
 */
typedef union
{
    /*! Storage for integer data */
    int i;
    /*! Storage for float data */
    float f;
} telemetry_union;

/**
 * Telemetry data types - each enum corresponds to a
 * a member of telemetry_union.
 */
typedef enum
{
    /*! Indicates stored integer data */
    TELEMETRY_TYPE_INT = 0,
    /*! Indicates stored float data */
    TELEMETRY_TYPE_FLOAT
} telemetry_data_type;

/**
 * Telemetry source structure.
 */
typedef struct
{
    /*! Source identifier - used for subscribing */
    uint8_t topic_id;
    /*! Data type identifier */    
    telemetry_data_type data_type;
    /*! Subsystem identifier */
    uint8_t subsystem_id;
} telemetry_source;

/**
 * Basic telemetry packet structure - encapsulating routing information
 * and data.
 */
typedef struct
{
    /*! Telemetry source structure */
    telemetry_source source;
    /*! Data payload */
    telemetry_union data;
    /*! Timestamp indicating packet creation time */
    uint16_t timestamp;
} telemetry_packet;

#endif

/* @} */