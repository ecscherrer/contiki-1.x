/*
 * Copyright (c) 2002, Adam Dunkels.
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
 * This file is part of the Contiki desktop environment
 *
 * $Id: www-conf.h,v 1.11 2004/09/19 20:05:40 adamdunkels Exp $
 *
 */
#ifndef __WWW_CONF_H__
#define __WWW_CONF_H__

#define WWW_CONF_HOMEPAGE "http://contiki.c64.org/"

/* The size of the HTML viewing area. */
#define WWW_CONF_WEBPAGE_WIDTH 36
#define WWW_CONF_WEBPAGE_HEIGHT 17

/* The size of the "Back" history. */
#define WWW_CONF_HISTORY_SIZE 2

/* Defines the maximum length of an URL */
#define WWW_CONF_MAX_URLLEN 55

/* The maxiumum number of widgets (i.e., hyperlinks, form elements) on
   a page. */
#define WWW_CONF_MAX_NUMPAGEWIDGETS 8

/* Turns <center> support on or off; must be on for forms to work. */
#define WWW_CONF_RENDERSTATE 0

/* Toggles support for HTML forms. */
#define WWW_CONF_FORMS       0

/* Maximum lengths for various HTML form parameters. */
#define WWW_CONF_MAX_FORMACTIONLEN  30
#define WWW_CONF_MAX_FORMNAMELEN    20
#define WWW_CONF_MAX_INPUTNAMELEN   20

#define WWW_CONF_MAX_INPUTVALUELEN  (WWW_CONF_WEBPAGE_WIDTH - 1)

#endif /* __WWW_CONF_H__ */
