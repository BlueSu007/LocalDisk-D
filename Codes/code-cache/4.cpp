// 比较两个运算符的优先级
// -1:s1<s2  0:s1==s2  1:s1>s2
int compare(string s1, string s2){
	if(s1.empty()){
		return 1;
	}
	
	if((s1=="+" || s1=="-" )&& (s2=="*" || s2=="/")){
		return -1;
	}
	if(((s1=="+" || s1=="-") && (s2=="+" || s2=="-")) ||
		((s1=="*" || s1=="/") && (s2=="*" || s2=="/"))){
			return 0;
		}
	if((s1=="*" || s1=="/") && (s2=="+" || s2=="-")){
		return 1;
	}
}
 
BiTree createTree(vector<string> data, int start, int end){
	// 去掉最外侧括号
	if(data[start] == "(" && data[end] == ")"){
		start++; end--;
	}
	
	BiTree T = new BiTNode;
	int size = end-start+1;
	
	if(size <= 0){
		return NULL;
	} 
	
	// 长度为1, 数字直接作为叶结点
	else if(size == 1){
		T->s = data[start];
		T->lchild = T->rchild = NULL; 
		return T;
		
	} else {
		string chosen;   // 记录选中的运算符
		int lcount = 0, mid;  // lcount记录左括号数量，mid记录选中运算符位置
		for(int i=start; i<=end; i++){
			if(data[i] == "(") lcount++;  // 这两行用于记录括号匹配是否结束
			if(data[i] == ")") lcount--;
			
			// isFour()用于判断是否是四则运算符, lcount==0表示外层不存在括号, 
			// compare()用于比较两运算符优先级 
			if(isFour(data[i]) && lcount==0 && compare(chosen, data[i]) != -1){
				chosen = data[i];  mid = i;
			}
		}
		T->s = chosen;
		// 对左右子树分别赋值，递归调用此函数 
		T->lchild = createTree(data, start, mid-1);
		T->rchild = createTree(data, mid+1, end);
		return T;
	}
}