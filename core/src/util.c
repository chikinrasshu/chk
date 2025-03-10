#include "chk/fmt.h"
#include <chk/util.h>

void size_to_str(Str buf, Size buf_size, U64 n) {
  U64 tbs = n / terabytes(1);
  n = n % terabytes(1);
  U64 gbs = n / gigabytes(1);
  n = n % gigabytes(1);
  U64 mbs = n / megabytes(1);
  n = n % megabytes(1);
  U64 kbs = n / kilobytes(1);
  n = n % kilobytes(1);

  if (tbs) {
    format_str(buf, buf_size, "%lluTb %lluGb %lluMb %lluKb %llub", //
               tbs, gbs, mbs, kbs, n);
  } else {
    if (gbs) {
      format_str(buf, buf_size, "%lluGb %lluMb %lluKb %llub", //
                 gbs, mbs, kbs, n);
    } else {
      if (mbs) {
        format_str(buf, buf_size, "%lluMb %lluKb %llub", //
                   mbs, kbs, n);
      } else {
        if (kbs) {
          format_str(buf, buf_size, "%lluKb %llub", //
                     kbs, n);
        } else {
          format_str(buf, buf_size, "%llub", //
                     n);
        }
      }
    }
  }
}
