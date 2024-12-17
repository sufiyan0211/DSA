vector<int>LargestFraction(int n, int d){
	// Code here
	int num = -1, den = 1;

    for (int i = 1; i <= 10000; i++) {
        if (i != d) {
            int x = (n * i) / d;
            if (1.0 * num / den < 1.0 * x / i
                && __gcd(x, i) == 1) {
                num = x;
                den = i;
            }
        }
    }

    vector<int> v;
    v.push_back(num);
    v.push_back(den);
    return v;
}