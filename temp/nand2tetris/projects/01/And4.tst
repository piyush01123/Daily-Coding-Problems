
load And4.hdl,
output-file And4.out,
output-list a%B1.4.1 b%B1.4.1 out%B1.4.1;

set a %B0000,
set b %B0000,
eval,
output;

set a %B0101,
set b %B0101,
eval,
output;

set a %B0101,
set b %B1010,
eval,
output;

set a %B1111,
set b %B1111,
eval,
output;
