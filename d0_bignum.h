#include "d0.h"
#include "d0_iobuf.h"

typedef struct d0_bignum_s d0_bignum_t;

WARN_UNUSED_RESULT BOOL d0_iobuf_write_bignum(d0_iobuf_t *buf, const d0_bignum_t *bignum);
WARN_UNUSED_RESULT d0_bignum_t *d0_iobuf_read_bignum(d0_iobuf_t *buf, d0_bignum_t *bignum);

void d0_bignum_INITIALIZE();
void d0_bignum_SHUTDOWN();

WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_new();
void d0_bignum_free(d0_bignum_t *a);
void d0_bignum_init(d0_bignum_t *b);
void d0_bignum_clear(d0_bignum_t *a);
WARN_UNUSED_RESULT size_t d0_bignum_size(const d0_bignum_t *r);
WARN_UNUSED_RESULT int d0_bignum_cmp(const d0_bignum_t *a, const d0_bignum_t *b);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_rand_range(d0_bignum_t *r, const d0_bignum_t *min, const d0_bignum_t *max);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_rand_bit_atmost(d0_bignum_t *r, size_t n);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_rand_bit_exact(d0_bignum_t *r, size_t n);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_zero(d0_bignum_t *r);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_one(d0_bignum_t *r);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_int(d0_bignum_t *r, int n);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_mov(d0_bignum_t *r, const d0_bignum_t *a);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_neg(d0_bignum_t *r, const d0_bignum_t *a);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_shl(d0_bignum_t *r, const d0_bignum_t *a, ssize_t n);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_add(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *b);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_sub(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *b);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_mul(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *b);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_divmod(d0_bignum_t *q, d0_bignum_t *m, const d0_bignum_t *a, const d0_bignum_t *b); // only do mod if both are NULL
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_mod_add(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *b, const d0_bignum_t *m);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_mod_mul(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *b, const d0_bignum_t *m);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_mod_pow(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *b, const d0_bignum_t *m);
WARN_UNUSED_RESULT BOOL d0_bignum_mod_inv(d0_bignum_t *r, const d0_bignum_t *a, const d0_bignum_t *m);
WARN_UNUSED_RESULT int d0_bignum_isprime(d0_bignum_t *r, int param);
WARN_UNUSED_RESULT d0_bignum_t *d0_bignum_gcd(d0_bignum_t *r, d0_bignum_t *s, d0_bignum_t *t, const d0_bignum_t *a, const d0_bignum_t *b);

WARN_UNUSED_RESULT char *d0_bignum_tostring(const d0_bignum_t *x, unsigned int base); // allocates!