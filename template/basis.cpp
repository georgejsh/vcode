/// Name: find basis vectors
/// Guarantee: void insertVector(int mask) {
const int LOG_A = 20;
int base[LOG_A], sz;

bool checkXor(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!base[i]) return false;
 
		mask ^= base[i];
	}
 
	return true;
}

void insertVector(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!base[i]) {
			base[i] = mask;
			sz++;
 
			return;
		}
 
		mask ^= base[i];
	}
}
 
 