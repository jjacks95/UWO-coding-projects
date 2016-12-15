# search.py
# ---------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

"""
In search.py, you will implement generic search algorithms which are called 
by Pacman agents (in searchAgents.py).
"""

import util
import copy

class SearchProblem:
  """
  This class outlines the structure of a search problem, but doesn't implement
  any of the methods (in object-oriented terminology: an abstract class).
  
  You do not need to change anything in this class, ever.
  """
  
  def getStartState(self):
     """
     Returns the start state for the search problem 
     """
     util.raiseNotDefined()
    
  def isGoalState(self, state):
     """
       state: Search state
    
     Returns True if and only if the state is a valid goal state
     """
     util.raiseNotDefined()

  def getSuccessors(self, state):
     """
       state: Search state
     
     For a given state, this should return a list of triples, 
     (successor, action, stepCost), where 'successor' is a 
     successor to the current state, 'action' is the action
     required to get there, and 'stepCost' is the incremental 
     cost of expanding to that successor
     """
     util.raiseNotDefined()

  def getCostOfActions(self, actions):
     """
      actions: A list of actions to take
 
     This method returns the total cost of a particular sequence of actions.  The sequence must
     be composed of legal moves
     """
     util.raiseNotDefined()
           

def tinyMazeSearch(problem):
  """
  Returns a sequence of moves that solves tinyMaze.  For any other
  maze, the sequence of moves will be incorrect, so only use this for tinyMaze
  """
  from game import Directions
  s = Directions.SOUTH
  w = Directions.WEST
  return  [s,s,w,s,w,w,s,w]

def depthFirstSearch(problem):
	"""
	Search the deepest nodes in the search tree first [p 85].

	Your search algorithm needs to return a list of actions that reaches
	the goal.  Make sure to implement a graph search algorithm [Fig. 3.7].

	To get started, you might want to try some of these simple commands to
	understand the search problem that is being passed in:
	"""
	start = problem.getStartState()
	fringe = util.Stack()
	
	#push start state to list plus two arrays for direction and cost variables
	fringe.push((start, []))
	explored = []
	
	#while the node list is not empty pop a node storing location, direction, and visited
	while not fringe.isEmpty():
		state, actions = fringe.pop()
		
		"""
		for the three variables in the node
		check if location was visited if not
		check if location is goal state
		if true return the action list 
		which contains the start state direction plus new direction
		"""
		
		for location, move, cost in problem.getSuccessors(state):
			
			if not location in explored:	
				goal_found = problem.isGoalState(location)
				if goal_found:
					actions_list = actions + [move]
					return actions_list
				"""
				if location not goal state push new successor location 
				and variables to node list to pop and continue search
				"""
				explored.append(location)
				fringe.push((location, actions + [move]))
	
	util.raiseNotDefined()
	
def breadthFirstSearch(problem):
	"Search the shallowest nodes in the search tree first. [p 81]"
	"""
	Used same method as depth first slightly altering
	node list to Queue instead of Stack as BFS is FIFO
	while DFS is LIFO
	"""
	
	start = problem.getStartState()
	
	fringe = util.Queue()
	fringe.push((start, []))
	explored = []
	
	while not fringe.isEmpty():
		state, actions  = fringe.pop()
		successor = problem.getSuccessors(state)
		
		for location, move, cost in successor:
			
			if not location in explored:
				goal_found = problem.isGoalState(location)
				
				if goal_found:
					actions_list =  actions + [move]
					return actions_list
				
				fringe.push((location, actions + [move]))
				explored.append(location)
				

	util.raiseNotDefined()
      
def uniformCostSearch(problem):
	"Search the node of least total cost first. "
	"""
	UCS search is performed very similarly to DFS and BFS
	altering for cost and making the visited a separate array
	first checking if state is goal state if so returning the list of actions
	for loop to process and push successors when goal state not found
	"""

	start = problem.getStartState()
	explored = []
	fringe = util.PriorityQueue()
	#push starting state, action, visited and cost
	fringe.push((start, []), 0)

	while not fringe.isEmpty():
		state, actions = fringe.pop()
		
		goal_found = problem.isGoalState(state)
		
		if goal_found:
			return actions
		
		successor = problem.getSuccessors(state)	
		
		for location, move, cost in successor:
			
			if not location in explored:
				fringe.push((location, actions + [move]), problem.getCostOfActions(actions + [move]))
				explored.append(state)
				
	util.raiseNotDefined()

def nullHeuristic(state, problem=None):
  """
  A heuristic function estimates the cost from the current state to the nearest
  goal in the provided SearchProblem.  This heuristic is trivial.
  """
  
  "The Manhattan distance heuristic for a PositionSearchProblem"
  xy1 = state
  xy2 = problem.goal
  return abs(xy1[0] - xy2[0]) + abs(xy1[1] - xy2[1])
  
  """
  "The Euclidean distance heuristic for a PositionSearchProblem"
  xy1 = state
  xy2 = problem.goal
  return ( (xy1[0] - xy2[0]) ** 2 + (xy1[1] - xy2[1]) ** 2 ) ** 0.5
  """
def aStarSearch(problem, heuristic=nullHeuristic):
	"Search the node that has the lowest combined cost and heuristic first."
	"""
	astar search is very similar to UCS still using priority queue difference is in pushing
	the heuristic function for cost in order to search combined cost and heuristic
	otherwise same general method for searching as UCS BFS and DFS
	"""
	start = problem.getStartState()
	fringe = util.PriorityQueue()
	fringe.push((start, []), [])
	explored = []
	
	while not fringe.isEmpty():
		state, actions = fringe.pop()
		
		goal_found = problem.getSuccessors(state)
		
		if goal_found:
			return actions
		successor = problem.getSuccessors(state)
		
		for location, moves, cost in successor:
			if not location in explored:	
				actions_list = actions + [moves]
				fringe.push((location, actions_list), (problem.getCostOfActions(actions_list) + heuristic(location, problem)))
				explored.append(state)
	
	util.raiseNotDefined()
    
  
# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch