/**
 * \file
 * uIP configuration file.
 * \author Adam Dunkels <adam@dunkels.com>
 *
 * This file contains configuration options for the uIP TCP/IP
 * stack. Each Contiki port will contain its own uip-conf.h file
 * containing architecture specific configuration options.
 *
 */

/*
 * Copyright (c) 2003, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution. 
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.  
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 *
 * This file is part of the Contiki Destop OS
 *
 * $Id: uip-conf.h,v 1.1 2006/04/17 15:11:46 kthacker Exp $
 *
 */
#ifndef __UIP_CONF_H__
#define __UIP_CONF_H__

/**
 * The maximum number of TCP connections.
 *
 * Since the TCP connections are statically allocated, turning this
 * configuration knob down results in less RAM used. Each TCP
 * connection requires approximatly 30 bytes of memory.
 */
#define UIP_CONF_MAX_CONNECTIONS 40

/**
 * The maximum number of listening TCP ports.
 *
 * Each listening TCP port requires 2 bytes of memory.
 */
#define UIP_CONF_MAX_LISTENPORTS 40

/**
 * The size of the uIP packet buffer.
 *
 * The uIP packet buffer should not be smaller than 60 bytes, and does
 * not need to be larger than 1500 bytes. Lower size results in lower
 * TCP throughput, larger size results in higher TCP throughput.
 */
#define UIP_CONF_BUFFER_SIZE     400

/**
 * The host byte order.
 *
 * Used for telling uIP if the architecture has LITTLE_ENDIAN or
 * BIG_ENDIAN byte order. x86 CPUs have LITTLE_ENDIAN byte order,
 * whereas Motorola CPUs have BIG_ENDIAN. Check the documentation of
 * the CPU to find out the byte order.
 */
#define UIP_CONF_BYTE_ORDER      LITTLE_ENDIAN


/**
 * IP address configuration through ping.
 *
 * uIP features IP address configuration using an ICMP echo (ping)
 * packet. In this mode, the destination IP address of the first ICMP
 * echo packet that is received is used to set the host IP address.  
 */
#define UIP_CONF_PINGADDRCONF    0
#endif /* __UIP_CONF_H__ */
