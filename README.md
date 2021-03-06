# LaneLinux  
### Pipeline.   
At First,  resize the image and then  convert frame as Bird view and then use a combination of color and gradient thresholds to generate a binary image.  
**Step 1:** Undisort Image.   
**Step 2:** Binary Image.   
**Step 3:** Take a histogram along all the columns in the lower half of the image and split histogram for two sides for each lane.   
**Step 4:** Use the two highest peaks from histogram as a starting point for determining where the lane lines are, and then use sliding windows moving upward in the image to determine where the lane lines go.   
Example: 
<p align="center">
  <img width="640" height="640" src="https://github.com/apreddyy/LaneandYolovehicle-Detection/blob/master/images/image2.png">
</p>  


**Step 5:**  Identify lane-line pixels.  
Find all non zero pixels.  
Example:   
<p align="center">
  <img width="640" height="360" src="https://github.com/apreddyy/LaneandYolovehicle-Detection/blob/master/images/image3.png">
</p> 


**Step 6:** Fit their positions with a polynomial.   
After performing 2nd order polynomial fit for nonzero pixels, drawing polyline and unwrap image the final output.  
Example:   
<p align="center">
  <img width="640" height="360" src="https://github.com/apreddyy/LaneandYolovehicle-Detection/blob/master/images/image4.png">
</p> 



## Dependencies and Compiling.  
1- Ubuntu 18.04.01 .  
2- OpenCV 3.4 or greater.  
3- openMP required.   
4- Run LaneDetection.sh, this script will compile and run the code.  
