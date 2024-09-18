int addnums(int *nums, int n) {
int sum = 0;
for (int i = 0; i < n; ++i) {
sum += *nums++;
}
return sum;
}
