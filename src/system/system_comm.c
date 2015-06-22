/*
 * Copyright (C) 2015 Officine Robotiche
 * Author: Raffaello Bonghi
 * email:  raffaello.bonghi@officinerobotiche.it
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU Lesser General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
#include <xc.h>
#elif defined(__C30__)
#if defined(__dsPIC33E__)
#include <p33Exxxx.h>
#elif defined(__dsPIC33F__)
#include <p33Fxxxx.h>
#endif
#endif

#include "system/system_comm.h"

#include "system/system.h"

#include <system/events.h>

/*****************************************************************************/
/* Global Variable Declaration                                               */
/*****************************************************************************/

/** GLOBAL VARIBLES */
// From system/system.c
extern system_parameter_t parameter_system;
// From communication/serial.c
extern system_error_serial_t serial_error;

/*****************************************************************************/
/* User Functions                                                            */
/*****************************************************************************/

void save_frame_system(packet_information_t* list_send, size_t* len, packet_information_t* info) {
    message_abstract_u send;
    switch (info->command) {
        case SYSTEM_SERVICE:
            send.system.service = services(info->message.system.service);
            list_send[(*len)++] = createDataPacket(info->command, info->type, &send);
            break;
        case SYSTEM_TASK_PRIORITY:
        case SYSTEM_TASK_FRQ:
            set_process(info->command, info->message.system.task);
            list_send[(*len)++] = createPacket(info->command, PACKET_ACK, info->type, NULL);
            break;
        default:
            list_send[(*len)++] = createPacket(info->command, PACKET_NACK, info->type, NULL);
            break;
    }
}

void send_frame_system(packet_information_t* list_send, size_t* len, packet_information_t* info) {
    message_abstract_u send;
    switch (info->command) {
        case SYSTEM_SERVICE:
            send.system.service = services(info->message.system.service);
            list_send[(*len)++] = createDataPacket(info->command, info->type, &send);
            break;
        case SYSTEM_TASK_PRIORITY:
        case SYSTEM_TASK_FRQ:
        case SYSTEM_TASK_TIME:
            
            break;
        case SYSTEM_TASK_NUM:
            send.system.task = get_process(info->command, info->message.system.task);
            list_send[(*len)++] = createDataPacket(info->command, info->type, &send);
            break;
        case SYSTEM_TASK_NAME:
            send.system.task_name = get_process_name(info->message.system.task_name);
            list_send[(*len)++] = createDataPacket(info->command, info->type, &send);
            break;
        case SYSTEM_PARAMETER:
            send.system.parameter = parameter_system;
            list_send[(*len)++] = createDataPacket(info->command, info->type, &send);
            break;
        case SYSTEM_SERIAL_ERROR:
            send.system.error_serial = serial_error;
            list_send[(*len)++] = createDataPacket(info->command, info->type, &send);
            break;
        default:
            list_send[(*len)++] = createPacket(info->command, PACKET_NACK, info->type, NULL);
            break;
    }
}