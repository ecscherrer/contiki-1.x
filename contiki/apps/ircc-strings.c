/*
 * Copyright (c) 2004, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 *
 * This file is part of the Contiki operating system.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 * $Id: ircc-strings.c,v 1.4 2004/09/12 20:24:54 adamdunkels Exp $
 */
const char ircc_strings_nick[6] = 
/* "NICK " */
{0x4e, 0x49, 0x43, 0x4b, 0x20, };
const char ircc_strings_crnl_user[8] = 
/* "\r\nUSER " */
{0xd, 0xa, 0x55, 0x53, 0x45, 0x52, 0x20, };
const char ircc_strings_contiki[10] = 
/* " contiki " */
{0x20, 0x63, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x20, };
const char ircc_strings_colon_contiki[12] = 
/* " :Contiki\r\n" */
{0x20, 0x3a, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0xd, 0xa, };
const char ircc_strings_join[6] = 
/* "JOIN " */
{0x4a, 0x4f, 0x49, 0x4e, 0x20, };
const char ircc_strings_crnl[3] = 
/* "\r\n" */
{0xd, 0xa, };
const char ircc_strings_part[6] = 
/* "PART " */
{0x50, 0x41, 0x52, 0x54, 0x20, };
const char ircc_strings_list[6] = 
/* "LIST " */
{0x4c, 0x49, 0x53, 0x54, 0x20, };
const char ircc_strings_privmsg[9] = 
/* "PRIVMSG " */
{0x50, 0x52, 0x49, 0x56, 0x4d, 0x53, 0x47, 0x20, };
const char ircc_strings_colon[3] = 
/* " :" */
{0x20, 0x3a, };
const char ircc_strings_ping[6] = 
/* "PING " */
{0x50, 0x49, 0x4e, 0x47, 0x20, };
const char ircc_strings_notice[8] = 
/* "NOTICE " */
{0x4e, 0x4f, 0x54, 0x49, 0x43, 0x45, 0x20, };
const char ircc_strings_action[9] = 
/* "\01ACTION " */
{0x1, 0x41, 0x43, 0x54, 0x49, 0x4f, 0x4e, 0x20, };
const char ircc_strings_version[9] = 
/* "\01VERSION" */
{0x1, 0x56, 0x45, 0x52, 0x53, 0x49, 0x4f, 0x4e, };
const char ircc_strings_version_query[10] = 
/* "\01VERSION\01" */
{0x1, 0x56, 0x45, 0x52, 0x53, 0x49, 0x4f, 0x4e, 0x1, };
const char ircc_strings_ctcpcrnl[4] = 
/* "\01\r\n" */
{0x1, 0xd, 0xa, };
const char ircc_strings_version_string[21] = 
/* " Contiki 1.2-devel0 " */
{0x20, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x20, 0x31, 0x2e, 0x32, 0x2d, 0x64, 0x65, 0x76, 0x65, 0x6c, 0x30, 0x20, };
