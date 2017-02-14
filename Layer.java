import java.awt.Canvas;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

import javax.swing.SwingUtilities;
import javax.swing.Timer;
public class Layer extends Canvas implements ActionListener{
	TetrisShape current;
	TetrisShape next;
	int[][] mainlayer=new int[10][20];
	Color[][] layerColor=new Color[10][20];
	int cx,cy;
	int centerX, centerY;
	float pixelSize, rWidth = 600, rHeight = 600;
	float xP, yP;
	public Timer timer=null;
    Thread thread;
    Control control=new Control();
	boolean sign=false;
	//thread=new Thread(timer);
	public boolean endtouch=false;
	public int numLinesRemoved=0;
	public int level=1;
	String s="the-file-name.txt";
	
	
	
	
	class Control  implements MouseMotionListener,MouseListener,MouseWheelListener{
		
		public Control()
		{
		}
		@Override
		public void mouseWheelMoved(MouseWheelEvent evt) {
			// TODO Auto-generated method stub
			
			if(!sign){
				if(evt.getWheelRotation()>0){
					if(rotationPremise(1))
						current=current.rightRotation();
				}
				if(evt.getWheelRotation()<0){
					if(rotationPremise(0))
						current=current.leftRotation();
				}
				repaint();
			}
			
		}

		@Override
		public void mouseClicked(MouseEvent evt) {
			// TODO Auto-generated method stub
			if(!sign){
				if(SwingUtilities.isLeftMouseButton(evt)){
					if(moveRight()) cx--;
				}
				else if(SwingUtilities.isRightMouseButton(evt)){
					if(moveLeft()) cx++;
				}
				repaint();
			
		}
		}

		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mousePressed(MouseEvent evt) {
			
				xP = fx(evt.getX()); yP = fy(evt.getY());
				if(xP>50&&xP<150&&yP>-260&&yP<-220){
					System.exit(1);
					
	 			}
			// TODO Auto-generated method stub
			
		}
		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		@Override
		public void mouseMoved(MouseEvent evt) {
			
			
			boolean a=sign;
			xP = fx(evt.getX()); yP = fy(evt.getY());
			if(xP>-260&&xP<0&&yP>-260&&yP<260){
				sign=true;
				thread.stop();
				}
			else{
				sign=false;
				thread.start();
			}
			if(a!=sign) repaint();
			
			
		}
		@Override
		public void mouseDragged(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
	}
	 
	public int readfile(String s)
	{
    	String line=null;
    	FileReader fileReader = null;
		try {
			fileReader = new FileReader(s);
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader = 
                new BufferedReader(fileReader);

            try {
				while((line = bufferedReader.readLine()) != null) {
				    System.out.println(line);
				    
				}
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}   

            // Always close files.
            try {
				bufferedReader.close();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}  
		
		return Integer.parseInt(line);
		
	}
	 int iX(float x){
		 return Math.round(centerX + x/pixelSize);
		 }
	 
	 int iY(float y){
		 return Math.round(centerY - y/pixelSize);
		 }
	 
	 float fx(int x){
		 return (x - centerX) * pixelSize;
		 }
	 
	 float fy(int y){
		 return (centerY - y) * pixelSize;
		 }
	 
	 public void setGameControl(Control control)
		{
			this.addMouseMotionListener( control);
			this.addMouseListener(control);
			this.addMouseWheelListener(control);
		}

	Layer(){ 
		
		setGameControl(control);
		cx=5;
		cy=20;
		//timer = new Timer(500, this);
		thread=new Thread(timer);
		thread.timer=new Timer(500, this);
	    thread.start(); 
	}
	public void start(){;
		current=new TetrisShape();
		next=new TetrisShape();
		current.selectRandom();
		next.selectRandom();
		thread.start();
		
	}
	void initgr(Graphics g){  
		Dimension d = getSize();
		int maxX = d.width - 1, maxY = d.height - 1;
		pixelSize = Math.max(rWidth/maxX, rHeight/maxY);
		centerX = maxX/2; centerY = maxY/2;
		g.drawRect(iX(-250),iY(250),Math.round(250/pixelSize),Math.round(500/pixelSize));
		g.drawRect(iX(50),iY(250),Math.round(170/pixelSize),Math.round(100/pixelSize));
		g.drawRect(iX(50),iY(-210),Math.round(100/pixelSize),Math.round(40/pixelSize));
		//g.setFont(new Font("Helvetica",Font.PLAIN,(int)(20/pixelSize)));
		String text1="Level                        "+level;
		g.drawString(text1, iX(50), iY(50));
		String text2="Lines                        "+numLinesRemoved;
		g.drawString(text2, iX(50), iY(0));
		g.drawString("Score                    0", iX(50), iY(-50));
		g.drawString("QUIT", iX(75), iY(-230));
	}

	public void mainlayer(Graphics g,int x,int y,Color z){
		x=iX(-250+25*x-25);
		y=iY(-250+25*y);
		g.setColor(z);
		g.fillRect(x, y, Math.round(25/pixelSize), Math.round(25/pixelSize));
		g.setColor(Color.black);
		g.drawRect(x, y, Math.round(25/pixelSize), Math.round(25/pixelSize));
	}
	public void nextlayer(Graphics g,int x,int y,Color z){
		x=iX(160-25*2+25*x);
		y=iY(240-25+25*y);
		g.setColor(z);
		g.fillRect(x, y, Math.round(25/pixelSize), Math.round(25/pixelSize));
		g.setColor(Color.black);
		g.drawRect(x, y, Math.round(25/pixelSize), Math.round(25/pixelSize));
	}
	boolean moveLeft()
	{
		for (int i = 0; i < 4; ++i) {
	        int x = cx + current.x(i);
	        int y = cy + current.y(i);
	      
	        	if (x==10||mainlayer[x][y-1]==1||y==1||mainlayer[x-1][y-2]==1) return false;
	      
	        
	    }
	    return true;
	}
	boolean moveRight()
	{
		for (int i = 0; i < 4; ++i) {
	        int x = cx + current.x(i);
	        int y = cy + current.y(i);
	      
	       
	        	if(x==1||mainlayer[x-2][y-1]==1||y==1||mainlayer[x-1][y-2]==1) return false;
	    }
	    return true;
	}
	public void addShape(){
		
		for (int i = 0; i < 4; ++i) {
            int x = cx + current.x(i);
            int y = cy + current.y(i);
            mainlayer[x-1][y-1]=1;
            layerColor[x-1][y-1]=current.getColor();
		}
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if(endtouch){
			endtouch=false;
			current=next;
			next=new TetrisShape();
			next.selectRandom();
			cx=5;
			cy=20;
		}
		else{
			cy--;
		}
		repaint();
	}
	
	public void fillMainLayer(Graphics g)
	{
		for(int x=0;x<10;x++){
			for(int y=0;y<20;y++){
				if(mainlayer[x][y]==1)
					mainlayer(g,x+1,y+1,layerColor[x][y]);
			}
		}
		
		
	}
	
	public void fillNextLayer(Graphics g)
	{
		for (int i = 0; i < 4; ++i) {
            int x = next.x(i);
            int y = next.y(i);
            nextlayer(g,x,y,next.getColor());
		}
		
	}
	
	public void fillshipLayer(Graphics g)
	{

		for (int i = 0; i < 4; ++i) {
            int x = cx + current.x(i);
            int y = cy + current.y(i);
            mainlayer(g,x,y,current.getColor());
		}
		
	}
	public boolean rotationPremise(int k){
		TetrisShape newShape=null;
		//TetrisShape newShape=(k>0)?current.rotateRight():current.rotateLeft();
		if(k>0)
		{
			 newShape=current.rightRotation();
		}
		else
		{
			newShape=current.leftRotation();
		}
		for (int i = 0; i < 4; ++i) {
            int x = cx + newShape.x(i);
            int y = cy + newShape.y(i);
            if(x<1||x>10||y<1||y>20||mainlayer[x-1][y-1]==1) return false;
		}
		return true;
	}
	public void checkDropped(){
		for (int i = 0; i < 4; ++i) {
            int x = cx + current.x(i);
            int y = cy + current.y(i);
            if(y==1){
            	endtouch=true;
            	break;
            }
            else if(mainlayer[x-1][y-2]==1){
            	if(y>=19)
            	{
            		System.exit(0)
            		;
            	}
            	endtouch=true;
            	break;
            }
           
            
        }
		
	}
	
	  private void removeFullLines()
	    {
		  int numFullLines = 0;
		

	        for (int i = mainlayer[0].length - 1; i >= 0; i--) {
	            boolean lineIsFull = true;
	            for (int j = 0; j < mainlayer.length; j++) {
	                if (mainlayer[j][i] == 0) {
	                    lineIsFull = false;
	                    //break;
	                }
	            }
	            
	      
	            if (lineIsFull) {
	                numFullLines++;
	                for (int j = 0; j < mainlayer.length; j++)
	                {
	                for (int k = i; k < mainlayer[0].length - 1; k++) {
	                    
	                         //board[(k * BoardWidth) + j] = shapeAt(j, k + 1);
	                         mainlayer[j][k]=mainlayer[j][k+1];
	                         layerColor[j][k]=layerColor[j][k+1];
	                         
	                }
	                
	            }
	        }
	       

	       
	     }
	       
	        if (numFullLines > 0) {
	            numLinesRemoved += numFullLines;
	           
	            System.out.print(numLinesRemoved);
	            	            
	        }
	      
	    }
	
	public void paint(Graphics g){
		
		initgr(g);
		fillMainLayer(g);
		fillNextLayer(g);
		fillshipLayer(g);
	
	
		removeFullLines();
		checkDropped();
		
		if(endtouch){
			//level=b.getLevel();
			level=readfile(s);
			System.out.print(level);
			addShape();
			
			
		}
		if(sign){        
			g.setColor(Color.blue);
			g.drawRect(iX(-130-60),iY(25),Math.round(120/pixelSize),Math.round(50/pixelSize));
			g.drawString("PAUSE", iX(-170), iY(-12));
		}
	}
	

}


