class Binary {
	public static int digit(long n) {
		if ( n < 0 ) {
			n = -n;
		}
		int k = (int)(Math.log(n)/Math.log(2));
		return k+1;
	}
	public static String binary(long n) {
		boolean minus = false;
		if ( n < 0 ) {
			minus = true;
			n = -n;
		}
		String bin = new String();
		while ( n != 0 ) {
			long h = n / 2;
			long m = n - 2 * h;
			n = h;
			bin = "" + m + bin;
		}
		if ( minus ) {
			bin = "-" + bin;
		}
		return bin;
	}
	public static void main(String args[]) {
		long val = Long.parseLong(args[0]);
		String bin = binary(val);
		System.out.println(bin + " : " + val);
		System.out.println("digit = " + digit(val) + " : " + bin.length());

		java.math.BigInteger big = java.math.BigInteger.valueOf(val);
		System.out.println("BigInteger : " + big.toString(2));
	}
}
