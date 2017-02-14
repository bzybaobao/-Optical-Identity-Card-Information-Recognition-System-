import java.awt.Color;
import java.util.Random;



public class TetrisShape {

    enum Sevenshape {  Square, ZShape, InverseLShape, LShape, 
    	SShape, TShape, Line };

    private Sevenshape nowShape;
    private int axis[][];
    private int[][][] shapeTable;


    public TetrisShape() {
        axis = new int[4][2];
        setShape(Sevenshape.SShape);

    }
   
    public void setShape(Sevenshape shape) {

         shapeTable = new int[][][] {
 
            { { -1, -1 },   { -1, 0 },   { 0, -1 },   { 0, 0 } },
            { { -1, 0 },   { 0, 0 },   { 0, -1 },   { 1, -1 } },
            { { -1, -1 },   { -1, 0 },   { 0, -1 },   { 1, -1 } },
            { { -1, -1 },   { 0, -1 },   { 1, -1 },   { 1, 0 } },
            { { -1, -1 },   { 0, -1 },   { 0, 0},     { 1, 0 } },
            { { -1, -1 },   { 0, -1 },   { 1, -1 },   { 0, 0 } },
            { { -1, -1 },   { 0, -1 },   { 1, -1 },   { 2, -1 } }
            
  
        };
//Here we put one row of the coordiate values from the coordsTable to a coords array of a tetris piece. 
        for (int i = 0; i < 4 ; i++) {
            for (int j = 0; j < 2; ++j) {
                axis[i][j] = shapeTable[shape.ordinal()][i][j];
            }
        
        }
        nowShape = shape;

    }
    public void setX(int dest, int x) { axis[dest][0] = x; }
    public void setY(int dest, int y) { axis[dest][1] = y; }
    public int x(int dest) { return axis[dest][0]; }
    public int y(int dest) { return axis[dest][1]; }
    public Sevenshape getShape()  { return nowShape;}

    public void selectRandom()
    {

    	int x = (int) (50*Math.random()% 6) + 1;
        Sevenshape[] values = Sevenshape.values(); 
        setShape(values[x]);
    }

    public TetrisShape leftRotation() 
    {
        if (nowShape == Sevenshape.Square)
            return this;

        TetrisShape result = new TetrisShape();
        result.nowShape = nowShape;

        for (int i = 0; i < 4; ++i) {
            result.setX(i, 1+y(i));
            result.setY(i, -1-x(i));
            //result.setX(i, 1+y(i));
            //result.setY(i, 3-x(i));
        }
        return result;
    }

    public TetrisShape rightRotation()
    {
        if (nowShape == Sevenshape.Square)
            return this;

        TetrisShape result = new TetrisShape();
        result.nowShape = nowShape;

        for (int i = 0; i < 4; ++i) {
        	result.setX(i, -1-y(i));
            result.setY(i, x(i)-1);
            //result.setX(i, 3-y(i));
            //result.setY(i, x(i)-1);
        }
        return result;
    }
    public Color getColor(){
    	Color color;
    	switch(nowShape.name()){
    		case "Square": color=Color.yellow;break;
    		case "ZShape": color=Color.blue;break;
    		case "InverseLShape" : color=Color.pink;break;
    		case "LShape" : color=Color.red;break;
    		case "SShape" : color=Color.green;break;
    		case "TShape" : color=Color.orange;break;
    		case "Line" : color=Color.cyan;break;
    		default: color=Color.white;   	
    	}
		return color;
    }
}