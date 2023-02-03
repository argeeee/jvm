public class Program {
	private String firstField = "[firstField]";

	private Program() {
	}

	private String getField() {
		return firstField;
	}

	public static void main(String[] args) {
		System.out.println("Hello world!");

		var program = new Program();

		for (int i = 0; i < program.getField().length(); i++) {
			System.out.print("" + i + " ");
		}
		System.out.println();

		if (10 < program.hashCode()) {
			program.firstField = "true";
		}

	}
}
