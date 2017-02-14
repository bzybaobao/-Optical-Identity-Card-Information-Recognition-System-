
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.border.LineBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
public class myPanel extends JPanel{

   
			//add("Center",layer );
			//layer.start();
   
	public boolean isFinishSet = false;
	public int score=10;
	public int level=50;
	public double speed=1.0;
	public int pixelSize=30;
	data a =new data();
	public void set(int level)
	{
		this.level=level;
	}
	


	

	
	public myPanel() throws IOException{
		 
        
		this.setLayout(new GridLayout(6, 1));
		//this.setSize(600,600);
		//this.setLayout(new FlowLayout());
		/*
		 *
		 */
		JSlider scoreParameter = new JSlider();
		scoreParameter.setMinimum(1);
		scoreParameter.setMaximum(10);
		scoreParameter.setMinorTickSpacing(1);
		scoreParameter.setMajorTickSpacing(9);
		scoreParameter.setPaintTicks(true);
		scoreParameter.setPaintLabels(true);
		JLabel scoreFactor = new JLabel("Score Factor: " + scoreParameter.getValue());
		scoreParameter.addChangeListener(new ChangeListener() {
			
			@Override
			public void stateChanged(ChangeEvent e) {
				// TODO Auto-generated method stub
				if ((JSlider)e.getSource() == scoreParameter) {
					score = scoreParameter.getValue();
					scoreFactor.setText("Score Factor: " + score);
				}
			}
		});
		this.add(scoreFactor);
		this.add(scoreParameter);
		/*
		 *
		 */
		JSlider levelParameter = new JSlider();
		levelParameter.setMinimum(20);
		levelParameter.setMaximum(50);
		levelParameter.setMinorTickSpacing(1);
		levelParameter.setMajorTickSpacing(10);
		levelParameter.setPaintTicks(true);
		levelParameter.setPaintLabels(true);
		JLabel levelFactor = new JLabel("Level Factor: " + levelParameter.getValue());
		levelParameter.addChangeListener(new ChangeListener() {
			
			@Override
			public void stateChanged(ChangeEvent e) {
				// TODO Auto-generated method stub
				if ((JSlider)e.getSource() == levelParameter) {
					level = levelParameter.getValue();
					levelFactor.setText("Level Factor: " + level);
				}
			}
		});
		this.add(levelFactor);
		this.add(levelParameter);
		/*
		 * 
		 */
		JSlider speedParameter = new JSlider();
		speedParameter.setMinimum(1);
		speedParameter.setMaximum(10);
		speedParameter.setMinorTickSpacing(1);
		speedParameter.setMajorTickSpacing(9);
		speedParameter.setPaintTicks(true);
		speedParameter.setPaintLabels(true);
		JLabel speedFactor = new JLabel("Speed Factor: " + speedParameter.getValue()/10.0);
		speedParameter.addChangeListener(new ChangeListener() {
			
			@Override
			public void stateChanged(ChangeEvent e) {
				// TODO Auto-generated method stub
				if ((JSlider)e.getSource() == speedParameter) {
					speed = speedParameter.getValue()/10.0;
					speedFactor.setText("Speed Factor: " + speed);
				}
			}
		});
		this.add(speedFactor);
		this.add(speedParameter);

		/*
		 * 
		 */
		JSlider squareSize = new JSlider();
		squareSize.setMinimum(10);
		squareSize.setMaximum(30);
		squareSize.setMinorTickSpacing(1);
		squareSize.setMajorTickSpacing(10);
		squareSize.setPaintTicks(true);
		squareSize.setPaintLabels(true);
		JLabel squareFactor = new JLabel("Square Size: " + squareSize.getValue());
		squareSize.addChangeListener(new ChangeListener() {
			
			@Override
			public void stateChanged(ChangeEvent e) {
				// TODO Auto-generated method stub
				if ((JSlider)e.getSource() == squareSize) {
					pixelSize = squareSize.getValue();
					squareFactor.setText("Square Size: " + pixelSize);
				}
			}
		});
		this.add(squareFactor);
		this.add(squareSize);
		
		
		 
		JButton startBt = new JButton("open game");
	
		
		
		//startBt.setForeground(Color.BLACK);
		//startBt.setFont(new Font("黑体", Font.BOLD, 18));
		//startBt.setBackground(Color.WHITE);
		//startBt.setSize(400,30);
		//startBt.setBorder(new LineBorder(Color.BLACK));
		startBt.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
				//System.out.println(score);
				//data.setScore(score);
				//System.out.println(level);
				//data.setLevel(level);
				//System.out.println(speed);
				//data.setSpeed(speed);
				//System.out.println(pixelSize);
				//data.setPixelSize(pixelSize);
				new gameFrame();
				startBt.setEnabled(false);
		
				//startBt.setVisible(false);
				
				
				//add("Center",layer );
				//layer.start();
			}
		});
		this.add(startBt);
		
		
		JButton startBt1 = new JButton("adjust data");
		//startBt.setForeground(Color.BLACK);
		//startBt.setFont(new Font("黑体", Font.BOLD, 18));
		//startBt.setBackground(Color.WHITE);
		//startBt.setSize(400,30);
		//startBt.setBorder(new LineBorder(Color.BLACK));
		startBt1.addActionListener(new ActionListener(){
			
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
				System.out.println(score);
				//int b=getLevel();
				System.out.println(level);
				System.out.println(speed);
				System.out.println(pixelSize);
				a.setLevel(level);
				System.out.println(a.getLevel());
				
				PrintWriter writer = null;
				try {
					writer = new PrintWriter("the-file-name.txt");
				} catch (FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
		    	writer.println(Integer.toString(level));
		    	writer.close();
		    	
		    	
		    	
		    	
		    	/*
		    	String line=null;
		    	FileReader fileReader = null;
				try {
					fileReader = new FileReader("the-file-name.txt");
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
		            */
			}
		});
		this.add(startBt1);
		
		/*
		 * 
		 */
		JButton cancelBt = new JButton("CANCEL");
		//startBt.setForeground(Color.BLACK);
		//startBt.setFont(new Font("黑体", Font.BOLD, 18));
		//startBt.setBackground(Color.WHITE);
		//startBt.setSize(400,30);
		//startBt.setBorder(new LineBorder(Color.BLACK));
		cancelBt.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
		this.add(cancelBt);
	}
}