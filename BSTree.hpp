#include <iostream>

template<class T>
struct BSNode {
	BSNode(const T& data = T()) : _pLeft(nullptr), _pRight(nullptr), _data(data)
	{}

	BSNode<T> *_pLeft;
	BSNode<T> *_pRight;
	T _data;
};

template<class T>
class BSTree {
	public:
		typedef BSNode<T> Node;
		typedef Node* pNode;
	private:
		pNode _pRoot;
	public:
		BSTree() : _pRoot(nullptr)
		{}

		~BSTree() {
			_Destroy(_pRoot);
		}

		pNode find(const T& data) {
			pNode pCur = _pRoot;
			while(pCur) {
				if(data == pCur->_data) {
					return pCur;
				} else if (data < pCur->_data) {
					pCur = pCur->_pLeft;
				} else {
					pCur = pCur->_pRight;
				}
			}

			return nullptr;
		}

		bool insert(const T& data) {
			if(_pRoot == nullptr) {
				_pRoot = new Node(data);
				return true;
			}

			pNode pCur = _pRoot;
			pNode pParent = nullptr;

			while(pCur) {
				pParent = pCur;
				if(data < pCur->_data) {
					pCur = pCur->_pLeft;
				} else if(data > pCur->_data) {
					pCur = pCur->_pRight;
				} else {
					return false;
				}
			}

			pCur = new Node(data);
			if(data < pParent->_data) {
				pParent->_pLeft = pCur;
			} else {
				pParent->_pRight = pCur;
			}

			return true;
		}

		bool earse(const T& data) {
			if(_pRoot == nullptr) {
				return false;
			}
			
			pNode pCur = _pRoot;
			pNode pParent = nullptr;

			while(pCur) {
				pParent = pCur;
				if(data == pCur->_data) {
					break;
				} else if(data > pCur->_data) {
					pCur = pCur->_pRight;
				} else {
					pCur = pCur->_pLeft;
				}
			}

			if(pCur == nullptr){
				return false;
			}

			if(pCur->_pLeft == nullptr) {
				if(pCur == pParent) { //del is root
					_pRoot = pParent->_pRight;
					delete pCur;
					return true;
				}

				if(pParent->_pLeft == pCur) {
					pParent->_pLeft = pCur->_pRight;
				} else {
					pParent->_pRight = pCur->_pRight;
				}
				delete pCur;
			} else if(pCur->_pRight == nullptr) {
				if(pParent == pCur) {
					_pRoot = pCur->_pLeft;
					delete pCur;
					return true;
				}

				if(pParent->_pLeft == pCur) {
					pParent->_pLeft = pCur->_pLeft;
				} else {
					pParent->_pRight = pCur->_pLeft;
				}
				delete pCur;
			} else {
				//替换法，找右子树中最小的
				//pNode del = pCur->_pRight;
				//pNode delParent = pCur;

				//while(del->_pLeft) {
				//	delParent = del;
				//	del = del->_pLeft;
				//}

				//pCur->_data = del->_data;
				//if(delParent == pCur) {
				//	delParent->_pRight = del->_pRight;
				//} else {
				//	delParent->_pLeft = del->_pRight;
				//}
				//delete del;
				
				//左子树中最大的
				pNode del = pCur->_pLeft;	
				pNode delParent = pCur;

				while(del->_pRight != nullptr) {
					delParent = del;
					del = del->_pRight;
				}
				pCur->_data = del->_data;

				if(pCur == delParent) {
					delParent->_pLeft = del->_pLeft;
				} else{
					delParent->_pRight = del->_pLeft;
				}
				delete del;
			}

			return true;
		}

		void InOrder() {
			_InOrder(_pRoot);
		}

	private:
		void _InOrder(pNode pRoot) {
			if(pRoot) {
				_InOrder(pRoot->_pLeft);
				std::cout << pRoot->_data << " ";
				_InOrder(pRoot->_pRight);
			}
		}

		void _Destroy(pNode& pRoot) {
			if(pRoot) {
				_Destroy(pRoot->_pLeft);
				_Destroy(pRoot->_pRight);
				pRoot = nullptr;
			}
		}
};
