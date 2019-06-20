public class ex1_1{
	public static int c = 0;
	public static void inc(){
		for(int i = 0; i < 25000000; i++){
			c++;
		}
	}
	public static void dec(){
		for(int i = 0; i < 25000000; i++){
			c--;
		}
	}
	public static Runnable increase = new Runnable(){
		public void run(){
			inc();
		}
	};
	public static Runnable decrease = new Runnable(){
		public void run(){
			dec();
		}
	};
	public static void main(String[] args){
		Thread thread[] = new Thread[8];
		for(int i=0; i<4; i++){
			thread[i] = new Thread(increase);
		}
		for(int i=4; i<8; i++){
			thread[i] = new Thread(decrease);
		}
		for (int i=0; i<8; i++) {
			thread[i].start();
		}
		try{
			for(int i=0; i<8; i++){
				thread[i].join();
			}
		}catch(InterruptedException e){
		}
		System.out.printf("(%d)%n", c);
	}
}