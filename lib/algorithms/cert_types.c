/*
 * Copyright (C) 2011 Free Software Foundation, Inc.
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * The GnuTLS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA
 *
 */

#include <gnutls_int.h>
#include <algorithms.h>
#include <gnutls_errors.h>
#include <x509/common.h>

/**
 * gnutls_certificate_type_get_name:
 * @type: is a certificate type
 *
 * Convert a #gnutls_certificate_type_t type to a string.
 *
 * Returns: a string that contains the name of the specified
 *   certificate type, or %NULL in case of unknown types.
 **/
const char *
gnutls_certificate_type_get_name (gnutls_certificate_type_t type)
{
  const char *ret = NULL;

  if (type == GNUTLS_CRT_X509)
    ret = "X.509";
  if (type == GNUTLS_CRT_OPENPGP)
    ret = "OPENPGP";

  return ret;
}

/**
 * gnutls_certificate_type_get_id:
 * @name: is a certificate type name
 *
 * The names are compared in a case insensitive way.
 *
 * Returns: a #gnutls_certificate_type_t for the specified in a
 *   string certificate type, or %GNUTLS_CRT_UNKNOWN on error.
 **/
gnutls_certificate_type_t
gnutls_certificate_type_get_id (const char *name)
{
  gnutls_certificate_type_t ret = GNUTLS_CRT_UNKNOWN;

  if (strcasecmp (name, "X.509") == 0 || strcasecmp (name, "X509") == 0)
    return GNUTLS_CRT_X509;
  if (strcasecmp (name, "OPENPGP") == 0)
    return GNUTLS_CRT_OPENPGP;

  return ret;
}

static const gnutls_certificate_type_t supported_certificate_types[] = {
  GNUTLS_CRT_X509,
  GNUTLS_CRT_OPENPGP,
  0
};

/**
 * gnutls_certificate_type_list:
 *
 * Get a list of certificate types.  Note that to be able to use
 * OpenPGP certificates, you must link to libgnutls-extra and call
 * gnutls_global_init_extra().
 *
 * Returns: a zero-terminated list of #gnutls_certificate_type_t
 *   integers indicating the available certificate types.
 **/
const gnutls_certificate_type_t *
gnutls_certificate_type_list (void)
{
  return supported_certificate_types;
}



