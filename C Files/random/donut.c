int global_var = 100; // Global scope
void function_scope() {
int local_var = 200; // Function scope
if (1) {
int block_var = 300; // Block scope
static int static_var = 400; // Function scope,
// Who can see what?
global_var++; // OK: Visible
local_var++; // OK: Visible
block_var++; // OK: Visible
static_var++; // OK: Visible
}
block_var++; // ERROR: Out of scope
static_var++; // OK: Still visible
}
