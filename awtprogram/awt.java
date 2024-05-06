package awtprogram;
import java.awt.*;
import java.awt.event.*;
public class awt{
    public static void main(String[] args) {
        //create new frame(window)
        Frame frame =new Frame("Hello BCA");
        //create a new label
        Label label = new Label("Hello awt");
        //create new panel
        Panel panel = New panel();
        panel.add(button);
        frame.add(label);
        //frame.add(panel)
        //frame.add(text area)
        //frame.add(checkbox)
        //frame.add(choice)
        //frame.add(list)
        //create a button
        Button button =new Button("Click Me");
        //set size of the frame
        frame.setSize(600, 600);
        //Make the frame visible in the end
        frame.setVisible(true);
        //add components to the frame
       frame.addWindowListener(new WindowAdapter()){
        public void window
       
       TextArea textarea = new TextArea("this is a text area");
       Checkbox check= new Checkbox();
       Choice choice = new Choice();
       choice.add("option 1");
       choice.add("option 2");
       choice.add("option 3");
       choice.add("option 4");



       }
       
    }
}