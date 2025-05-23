package inclass5;

/************************************************************
 *                                                          *
 *  CSCI 470/680     In-Class Exercise 5       Summer 2018  *                       
 *                                                          *
 *  Programmer:  Lucas Damler				                *   
 *                                                          *
 *  Date Due:    25 JUL 2018					            *                         
 *                                                          *
 ************************************************************/

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JButton;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.ListSelectionModel;
import javax.swing.ScrollPaneConstants;

public class EventsFrame extends JFrame 
{
   private JFrame mainFrame;		//main frame
   private JLabel statusLabel;		//status label
   private static final String[] animalNames = {"Elephant", "Rhinoceros", "Lion", "Hippopotamus"};		//animal name array
   private JRadioButton selectMe;		//radio button
   
   public EventsFrame()
   {   
      mainFrame = new JFrame("Events");
      mainFrame.setSize(500, 500);
      mainFrame.setLayout(new FlowLayout());
      mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
      statusLabel = new JLabel("", JLabel.CENTER);
      statusLabel.setSize(50,50);
      
      mainFrame.add(statusLabel);
      mainFrame.setVisible(true);
//TEXTBOX
      JTextArea t1 = new JTextArea();
      JScrollPane scroll = new JScrollPane(
    		  t1, ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
    		  	  ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
      t1.setBounds(10,10,460,350);		//set text area bounds
      mainFrame.add(t1, BorderLayout.CENTER);
      
      JButton showButton = new JButton("Clear");
      showButton.setBounds(395,395, 75,20);
      showButton.addActionListener(new ActionListener() {		//on click clears text area
    	  public void actionPerformed(ActionEvent e) {
    		  String temp = "";
    		  t1.setText(temp);
    	  }
      });
      
      mainFrame.add(showButton);
//JCOMBOBOX     
      JComboBox<String> animalBox = new JComboBox<String>(animalNames);		//create JCombo for animal names
      animalBox.setSelectedItem(0);
      
      JScrollPane animalScroll = new JScrollPane(animalBox);
      animalScroll.setBounds(20,390, 120,40);		//set scroll bounds
//JLIST      
      JList<String> animalList = new JList<String>(animalNames); // list of animal names
      animalList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
      animalList.setSelectedIndex(0);
      
      animalList.setBounds(280,370, 100,75); 
      
      animalList.addListSelectionListener(		//get selection for JLIST on click
         new ListSelectionListener()
         {
    	    @Override
    		public void valueChanged(ListSelectionEvent event)
    	    {
    		   String temp = "";
    	       temp = "JLIST Animal Selected: " + animalNames
    	    		   [animalList.getSelectedIndex()];
    	       t1.setText(temp);
    	    }
         });
      
      mainFrame.add(animalScroll);		//add animal scroll list to frame
      mainFrame.add(animalList);		//add animal list to frame
//RADIO BUTTON
      selectMe = new JRadioButton("Select Me", false);		//set radio button to false
      selectMe.setBounds(150,390, 90,40);
      mainFrame.add(selectMe);			//add radio button to frame
      
      selectMe.addActionListener(new ActionListener() {		//Get selection for JCSROLL using radio button
    	  public void actionPerformed(ActionEvent e) {
    		  String temp = "";
    		  if(animalBox.getSelectedIndex() != -1) {
    			  temp = "JSCROLL Animal Selected: " + animalBox.getItemAt
    					  (animalBox.getSelectedIndex());
    		  }
    		  t1.setText(temp);
    	  }
      });
      
      mainFrame.setLayout(null);
      mainFrame.setVisible(true);
   } 
}
