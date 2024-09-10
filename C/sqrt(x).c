int mySqrt(int s) {
    if(s==0||s==1) {
		return s;
	}

	double xn = s/2;
	double tolerance = 1e-5;
	int max_iterations = 100;
	int iterations=0;

	while(iterations<max_iterations) {
		double next_xn = (xn + s / xn) / 2;

		if(fabs(next_xn - xn)<tolerance) {
			break;
		}

		xn = next_xn;
		iterations++;
	}
	
	int res = floor(xn);
	return res;
}
