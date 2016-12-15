
public class DataUpdating{

  //variables
  float calArraySum;
  float floorsArraySum;
  float stepsArraySum;
  float distanceArraySum;
  float actTimeArraySum;
  float sedTimeArraySum;

  //constructor
  public DataUpdating(){
    calArraySum = 0;
    floorsArraySum = 0;
    stepsArraySum = 0;
    distanceArraySum = 0;
    actTimeArraySum = 0;
    sedTimeArraySum = 0;


  }

//Sum Per Min for calories, floors, steps, and distance
  public DataUpdating SumPerMin(float calArray[], float floorsArray[], float stepsArray[], float distanceArray[]){
      int i;
      int MAX = 1140;
      float calArraySum = 0, floorsArraySum = 0, stepsArraySum = 0, distanceArraySum = 0;

      //for loops read through array, summing all values
      for(i = 0; i < MAX; i++){
        calArraySum += calArray[i];
      }

      for(i = 0; i < MAX; i++){
        floorsArraySum += floorsArray[i];
      }

      for(i = 0; i < MAX; i++){
        stepsArraySum += stepsArray[i];
      }
      for(i = 0; i < MAX; i++){
        distanceArraySum += distanceArray[i];
      }

      //creating object to hold all values
      DataUpdating PerMin = new DataUpdating();
      PerMin.calArraySum = calArraySum;
      PerMin.floorsArraySum = floorsArraySum;
      PerMin.stepsArraySum = stepsArraySum;
      PerMin.distanceArraySum = distanceArraySum;

      //return object
      return PerMin;

  }

  public DataUpdating SumBoolean(boolean actTimeArray[], boolean sedTimeArray[]){
      int i;
      int MAX = 1140;
      float actTimeArraySum = 0, sedTimeArraySum = 0;

      //for loop reads through entire array
      //checks if boolean value is true if so adds one
      for(i = 0; i < MAX; i++){
        if(actTimeArray[i] == true){
          actTimeArraySum += 1;
        }
      }
      for(i = 0; i < MAX; i++){
        if(sedTimeArray[i] == true){
          sedTimeArraySum += 1;
        }
      }

      //create object to hold boolean value totals
      DataUpdating Boolean = new DataUpdating();

      //store values in object
      Boolean.actTimeArraySum = actTimeArraySum;
      Boolean.sedTimeArraySum = sedTimeArraySum;

      //return object
      return Boolean;
  }

}
