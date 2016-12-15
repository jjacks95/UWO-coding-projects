import java.util.*;

public class BinarySearchTree implements BinarySearchTreeADT{
	//constructor for BST
	DictEntry root;
	DictEntry current_node;
	
	public BinarySearchTree(){
		root = null;
		current_node = null;
	}	  

	//find method returns node found with matching key
	public DictEntry find(Position key){
		DictEntry tmp;
		//check that current node is not null
		//else set to null
		if(current_node == null){
			current_node = root;
			return null;
		}
		
		//check if current node key is equal to passed key
		if(current_node.getPosition().compareTo(key) == 0){
			
			//if it is set tmp to current and current back to root 
			//returning tmp
			tmp = current_node;
			current_node = root;
			return tmp;
		}
		//check if key is less than or greater than current node key
		else if(current_node.getPosition().compareTo(key) == 1){
			//if less than set current to current left
			current_node = current_node.left;
			//recursive call of find
			return find(key);
		}
		else{
			//else set current to current right
			current_node = current_node.right;
			//recursive call of find
			return find(key);
			}
	}
	
	//insert method will create new node unless it already exists
	public void insert(DictEntry data) throws BSTException{
			DictEntry tmpNode;
			
			//check that tree is not empty
			if(root == null){
				
				//if empty set root to new node from passed data
				root = new DictEntry(data.getPosition(), data.getColor());
				current_node = root;
				return;
			}
			//check if current key is less than data key
			if(current_node.getPosition().compareTo(data.getPosition()) == 1){
				
				//check if current left is equal to null
				if(current_node.left != null){
					//if not null set current to current left and call insert
					current_node = current_node.left;
					insert(data);
				}else{
					//else set current left as new node to be added from data
					current_node.left = new DictEntry(data.getPosition(), data.getColor());
					tmpNode = current_node.left;
					tmpNode.parent = current_node;
				}	
			}
			//check if current key is less than data key
			if(current_node.getPosition().compareTo(data.getPosition()) == -1){
				
				//check if current right is null
				if(current_node.right != null){
					//if not null then set current to current right and call insert
					current_node = current_node.right;
					insert(data);
				}else{
					//if equal to null set current right to new node data
					current_node.right = new DictEntry(data.getPosition(), data.getColor());
					tmpNode = current_node.right;
					tmpNode.parent = current_node;
				
				}
			}
			//check that current node and data do not equal
			if(current_node.getPosition().compareTo(data.getPosition()) == 0){
				//if equal set current back to root and throw exception
				current_node = root;
				throw new BSTException("Already Exists");
			}
			
		current_node = root;
		} 
			
	//remove method will remove node and re establish link unless node doesnt exist
	public void remove(Position key) throws BSTException{
		DictEntry parent = root;
		DictEntry current = root;
		
		//isLeftChild indicates if we are the right or left child of current node
		boolean isLeftChild = false;
		
		//check if root is null
		if(root == null){
			//if null throw exception
			throw new BSTException("No Item to be Removed- Tree Emptry");
		}
		//check that  key is not equal to passed key
		while(current.getPosition().compareTo(key) !=0){
			//while it is not equal set current to parent
			parent = current;
			
			//check if it is less than or greater than current key 
			//to move left or right
			if(current.getPosition().compareTo(key) == 1){
				isLeftChild = true;
				current = current.left;
			}else{
				isLeftChild = false;
				current = current.right;
			}
			
			if(current == null){
				//if it traverses entire tree without finding a equal key
				//throw exception
				throw new BSTException("No Item to be Removed");
			}
		}
		
		//if current key is found that equals passed key
		//Case 1: if node to be deleted has no children
		if(current.left == null && current.right == null){
			//if both children are null
			//check if current is equal to root
			//if equal set root to null
			if(current == root){
				root = null;
			}
			//if not then see if left child is true
			//indicating which parent pointer to remove to delete node
			if(isLeftChild == true){
				parent.left = null;
			}else{
				parent.right = null;
			}
		}
		//Case 2 : if node to be deleted has only one child
		else if(current.right == null){
			//if current right is null and left is not
			//check if current is equal to root if it is set root to current left
			if(current == root){
				root = current.left;
				
			//else if left child is true set parent left to current left
			//else set parent right to current right
			}else if(isLeftChild == true){
				parent.left = current.left;
			}else{
				parent.right = current.left;
			}
		}
		//if current left is null but current right is not
		else if(current.left == null){
			//check current is equal to root
			if(current==root){
				//if it is set root to current right
				root = current.right;
			
			//if left child is true set parent left to current right
			}else if(isLeftChild == true){
				parent.left = current.right;
			
			//else parent right to current right
			}else{
				parent.right = current.right;
			}
		//last case is if current has two children not null
		}else if(current.left!=null && current.right!=null){
			
			//we have found the minimum element in the right sub tree
			DictEntry successor	 = successor(current.getPosition());
			//check if current is root
			if(current == root){
				//if it is set root to successor
				root = successor;
			
			//else check if left child is true
			//if it is set parent left to successor else set parent right to successor
			}else if(isLeftChild == true){
				parent.left = successor;
			}else{
				parent.right = successor;
			}
			
			successor.left = current.left;
		}			
	}

	
	
public DictEntry successor(Position key){
		//this method will return the next value that is less than the key
		//but the geatest compared to the rest of the nodes less than
		
		DictEntry successsor = null;
		DictEntry successsorParent = null;
		DictEntry deleteNode;
		deleteNode = find(key);
		DictEntry tmp_parent = deleteNode.parent;
        DictEntry tmp_current = deleteNode;
		
		//check if find key returns null
		if (deleteNode == null){
            return null;
		}
		
		//if not does the right not equal null
        if (deleteNode.right != null){
			//if it does not then set current to delete right
			//and successor to smallest node in the current node subtree
			current_node = deleteNode.right;	
			successsor = smallest();
			current_node = root;
			return successsor;
 		}
		//finds successor will parent of the current node doesnt equal null
		//and current node is equal to parent right
		//traversing the right subtree for successor
        while (tmp_parent != null && tmp_current == tmp_parent.right){
            tmp_current = tmp_parent;
            tmp_parent = tmp_parent.parent;
        }
        return tmp_parent;	
		
	}	
	



public DictEntry predecessor(Position key){
		//this method will return the next value that is greater than the key
		//but the smallest compared to the rest of the nodes greater than
		
		DictEntry predecessor =null;
		DictEntry predecessorParent =null;
		DictEntry deleteNode;
		deleteNode = find(key);
		DictEntry tmp_parent = deleteNode.parent;
        DictEntry tmp_current = deleteNode;
		
		//check if node is null
		if (deleteNode == null){
            return null;
		}
        //check if left node is null
        if (deleteNode.left != null){
			//if not set current to left and predecessor to largest of subtree
			current_node = deleteNode.left;
			predecessor = largest();
			current_node = root;
			return predecessor;
			}		
	
		//finds successor will parent of the current node doesnt equal null
		//and current node is equal to parent left
		//traversing the left subtree for successor
        while (tmp_parent != null && tmp_current == tmp_parent.left){
            tmp_current = tmp_parent;
            tmp_parent = tmp_parent.parent;
        }
		return tmp_parent;
	}	
	
	//smallest method will return smallest node in tree
	public DictEntry smallest(){
		//method will traverse the left side of the tree until 
		//reaching the farthest left node which in a BST is the smallest
		if(current_node == null){
			return null;
		}
		
		while(current_node.left != null){
			current_node = current_node.left;
		}
			
		return current_node;
	}
	
	
	
	public DictEntry largest(){
		//method will traverse the right side of the tree until 
		//reaching the farthest right node which in a BST is the largest
		if(current_node == null){
			return null;
		}
		while(current_node.right != null){
			current_node = current_node.right;
		}
		return current_node;
	}
}
