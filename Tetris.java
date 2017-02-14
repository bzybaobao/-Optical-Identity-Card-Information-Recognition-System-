import java.awt.*;
import java.awt.event.*;
import java.io.FileNotFoundException;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

public class Tetris extends JFrame{
	public static void main(String[] args) throws IOException {
		new Tetris();
	}
	
	Tetris() throws IOException{ 
		super("Tetris");
		setIgnoreRepaint(true);
		addWindowListener(new WindowAdapter()
		{public void windowClosing(WindowEvent e){System.exit(0);}});
		setSize (600, 600);
		myPanel pan= new myPanel();
		//pan.setLayout(null);
		add(pan);
		
		//pan.setVisible(true);
		show();
		//this.setVisible(true);
		//show();
		//JPanel pan= new JPanel();
		//add(pan);
		//pan.setVisible(true);
		//JSlider scoreParameter = new JSlider();
		//pan.add(scoreParameter);
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		
		JSlider scoreParameter1 = new JSlider();
		pan.add(scoreParameter1);
	    JButton okButton = new JButton("OK");
		pan.add(okButton);
		okButton.setVisible(true);
		okButton.setLayout(null);
		okButton.setBounds(50, 50, 50, 50);
		*/
		//pan.setVisible(true);
		//add(pan);
		//Layer layer=new Layer();
		//add("Center",layer );
		//layer.start();
		//show();
		
	}
}
