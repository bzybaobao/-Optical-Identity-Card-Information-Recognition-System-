import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JPanel;
import javax.swing.JFrame;

public class gameFrame extends JFrame{
	
	gameFrame()
	{
		addWindowListener(new WindowAdapter()
		{public void windowClosing(WindowEvent e){System.exit(0);}});
		setSize (500, 400);
		setIgnoreRepaint(true);
		
		
		//setSize (500, 400);
		Layer layer=new Layer();
		add("Center",layer );
		layer.start();
		show();
		
	}
	

}
