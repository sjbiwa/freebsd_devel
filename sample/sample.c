/*
 * sample.c
 *
 *  Created on: 2015/09/26
 *      Author: biwa
 */
#include <sys/types.h>
#include <sys/module.h>
#include <sys/systm.h>
#include <sys/errno.h>
#include <sys/param.h>
#include <sys/kernel.h>

static int sample_loader(struct module *m, int what, void *arg)
{
  int err = 0;

  switch (what) {
  case MOD_LOAD:                /* kldload */
    uprintf("Skeleton KLD loaded.\n");
    break;
  case MOD_UNLOAD:
    uprintf("Skeleton KLD unloaded.\n");
    break;
  default:
    err = EOPNOTSUPP;
    break;
  }
  return(err);
}

/* Declare this module to the rest of the kernel */

static moduledata_t sample_mod = {
  "skel",
  sample_loader,
  NULL
};

DECLARE_MODULE(sample, sample_mod, SI_SUB_KLD, SI_ORDER_ANY);
