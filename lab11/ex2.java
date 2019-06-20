import java.util.concurrent.locks.*;

public class ex2{ 
	public static Lock lock = new ReentrantLock(); 
	private static Condition threadCond = lock.newCondition(); 
	private static int product = 0; 
	public static void setProduct()
	{ 
		lock.lock(); 
		try
		{ 	while(product == 10) 
			{ 
				try{threadCond.await();} 
				catch(InterruptedException e){e.printStackTrace();} 
			} 
		
			product += 1; 
			System.out.printf("To produce (%d)%n", product); 
			if(product == 10) System.out.println("full");
			threadCond.signal(); 
		} 
		finally{
			lock.unlock();
		} 
	}
	public static Runnable producer = new Runnable(){
		public void run(){
			setProduct();
		}
	};
	public static void getProduct()
	{ 	lock.lock(); 
		try 
		{ 
			while(product == 0) 
			{ 
				try{threadCond.await();} 
				catch(InterruptedException e){e.printStackTrace();} 
			} 
			product -= 1; 
			System.out.printf("To consume (%d)%n", product); 
			if(product == 0) System.out.println("empty");
			threadCond.signal(); 
		} 
		finally
		{
			lock.unlock();
		} 
	}
	public static Runnable consumer = new Runnable(){
		public void run(){
			getProduct();
		}
	};
	public static void main(String[] args) {
		Thread thread[] = new Thread[20];
		for(int i=0; i<10; i++){
			thread[i] = new Thread(producer);
		}
		for(int i=10; i<20; i++){
			thread[i] = new Thread(consumer);
		}
		for(int i=0; i<20; i++){
			thread[i].start();
		}
		try{
			for(int i=0; i<20; i++){
				thread[i].join();
			}
		}catch(InterruptedException e){
			
		}
	}
}