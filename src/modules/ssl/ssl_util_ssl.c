/*                      _             _
**  _ __ ___   ___   __| |    ___ ___| |
** | '_ ` _ \ / _ \ / _` |   / __/ __| |
** | | | | | | (_) | (_| |   \__ \__ \ | mod_ssl - Apache Interface to SSLeay
** |_| |_| |_|\___/ \__,_|___|___/___/_| http://www.engelschall.com/sw/mod_ssl/
**                      |_____|
**  ssl_util_ssl.c
**  Additional Utility Functions for SSLeay
*/

/* ====================================================================
 * Copyright (c) 1998-1999 Ralf S. Engelschall. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by
 *     Ralf S. Engelschall <rse@engelschall.com> for use in the
 *     mod_ssl project (http://www.engelschall.com/sw/mod_ssl/)."
 *
 * 4. The names "mod_ssl" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    rse@engelschall.com.
 *
 * 5. Products derived from this software may not be called "mod_ssl"
 *    nor may "mod_ssl" appear in their names without prior
 *    written permission of Ralf S. Engelschall.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by
 *     Ralf S. Engelschall <rse@engelschall.com> for use in the
 *     mod_ssl project (http://www.engelschall.com/sw/mod_ssl/)."
 *
 * THIS SOFTWARE IS PROVIDED BY RALF S. ENGELSCHALL ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL RALF S. ENGELSCHALL OR
 * HIS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */

#include "mod_ssl.h"


/*  _________________________________________________________________
**
**  Additional High-Level Functions for SSLeay
**  _________________________________________________________________
*/

int SSL_get_app_data2_idx(void)
{
   static int app_data2_idx = -1;

   if (app_data2_idx < 0) {
      app_data2_idx = SSL_get_ex_new_index(0, 
           "Second Application Data for SSL", NULL, NULL, NULL);
      app_data2_idx = SSL_get_ex_new_index(0, 
           "Second Application Data for SSL", NULL, NULL, NULL);
   }
   return(app_data2_idx);
}

void *SSL_get_app_data2(SSL *ssl)
{
    return (void *)SSL_get_ex_data(ssl, SSL_get_app_data2_idx());
}

void SSL_set_app_data2(SSL *ssl, void *arg)
{
    SSL_set_ex_data(ssl, SSL_get_app_data2_idx(), (char *)arg);
    return;
}

