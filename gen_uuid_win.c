
#include <rpc.h>
#ifdef uuid_t
#undef uuid_t
#endif // uuid_t
#include "uuid.h"

void uuid_generate_random(uuid_t out) {
  UuidCreate((UUID*) out);
}

void uuid_generate_time(uuid_t out) {
  UuidCreateSequential((UUID*) out);
}