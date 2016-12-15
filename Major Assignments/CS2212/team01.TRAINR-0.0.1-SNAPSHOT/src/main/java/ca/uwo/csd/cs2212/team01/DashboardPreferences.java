/**
 * 
 */
package ca.uwo.csd.cs2212.team01;

import java.io.Serializable;

public class DashboardPreferences implements Serializable{

	private boolean showCaloriesBurned;
	private boolean showTotalDistance;
	private boolean showFloorsClimbed;
	private boolean showStepsTaken;
	private boolean showActiveMinutes;
	private boolean showSedentaryMinutes;
	private boolean showTrainR;


	public DashboardPreferences(){
		boolean showCaloriesBurned = true;
		boolean showTotalDistance = true;
		boolean showFloorsClimbed = true;
		boolean showStepsTaken = true;
		boolean showActiveMinutes = true;
		boolean showSedentaryMinutes = true;
		boolean showTrainR = true;
	}


	public boolean isShowCaloriesBurned() {
		return showCaloriesBurned;
	}


	public void setShowCaloriesBurned(boolean showCaloriesBurned) {
		this.showCaloriesBurned = showCaloriesBurned;
	}


	public boolean isShowTotalDistance() {
		return showTotalDistance;
	}


	public void setShowTotalDistance(boolean showTotalDistance) {
		this.showTotalDistance = showTotalDistance;
	}


	public boolean isShowFloorsClimbed() {
		return showFloorsClimbed;
	}


	public void setShowFloorsClimbed(boolean showFloorsClimbed) {
		this.showFloorsClimbed = showFloorsClimbed;
	}


	public boolean isShowStepsTaken() {
		return showStepsTaken;
	}


	public void setShowStepsTaken(boolean showStepsTaken) {
		this.showStepsTaken = showStepsTaken;
	}


	public boolean isShowActiveMinutes() {
		return showActiveMinutes;
	}


	public void setShowActiveMinutes(boolean showActiveMinutes) {
		this.showActiveMinutes = showActiveMinutes;
	}


	public boolean isShowSedentaryMinutes() {
		return showSedentaryMinutes;
	}


	public void setShowSedentaryMinutes(boolean showSedentaryMinutes) {
		this.showSedentaryMinutes = showSedentaryMinutes;
	}


	public boolean isShowTrainR() {
		return showTrainR;
	}


	public void setShowTrainR(boolean showTrainR) {
		this.showTrainR = showTrainR;
	}

}