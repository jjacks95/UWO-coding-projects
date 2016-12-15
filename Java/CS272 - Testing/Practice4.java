/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package testing;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


/**
 *
 * @author Josh Jackson
 */
public class Practice4 {
    private static class HelloWorldDisplay extends JPanel{
        public void paintComponent(Graphics g)
        {
            super.paintComponent(g);
            g.drawString("Hello World!", 20, 30);
            
        }        
    }
    private static class ButtonHandler implements ActionListener{
        public void actionPerformed(ActionEvent e){
            System.exit(0);
        }
    }
    public static void main(String[] args){
        HelloWorldDisplay displayPanel = new HelloWorldDisplay();
        JButton okButton = new JButton("OK");
        ButtonHandler listener = new ButtonHandler();
        okButton.addActionListener(listener);
        
        JPanel content = new JPanel();
        content.setLayout(new BorderLayout());
        content.add(displayPanel, BorderLayout.CENTER);
        content.add(okButton, BorderLayout.SOUTH);
        
        JFrame window = new JFrame("GUI Test");
        window.setContentPane(content);
        window.setSize(500, 300);
        window.setLocation(250, 100);
        window.setVisible(true);
    }
}
