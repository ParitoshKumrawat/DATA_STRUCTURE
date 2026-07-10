class TreeNode:
     def __init__(self, x):
          self.data=x
          self.left=None
          self.right=None

def postOrder(root):
     postOrder=[]
     
     if root is None:
          return postOrder
     
     st1 =[]
     st2 =[]

     st1.append(root)

     while st1:
          root = st1.pop()
          st2.append(root)

          if root.left :
               st1.append(root.left)
        
          if root.right :
               st2.append(root.right)
        
     while st2:
          postOrder.append(st2.pop().data)
        
     return postOrder

if __name__ == "__main__":
     root = TreeNode(1)
     root.left = TreeNode(2)
     root.right = TreeNode(3)
     root.left.left = TreeNode(4)
     root.left.right = TreeNode(5)

     result = postOrder(root)

     print("Postorder : ",result)