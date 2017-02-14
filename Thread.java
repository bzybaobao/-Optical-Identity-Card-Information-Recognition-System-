import javax.swing.Timer;

public class Thread{
	//timer = new Timer(500, this);
	public  Timer timer;

	Thread(Timer timer){
		
                this.timer=timer;
	
	}
	void start(){
		timer.start();
	}
	void stop(){
		timer.stop();
	}
	public  Timer getTimer()
	{
		return timer;
		
	}
	
}