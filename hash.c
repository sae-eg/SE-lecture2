// 0 hash値を求める関数　bucketsizeで割る,
// 1 hashtableにデータ入れる関数、配列中身０にしておいて、0であれば数字入れる、0でなければ再ハッシュ関数にまわす
// 2　searchする関数　hash値求めて、違ったら再ハッシュ
// 3 衝突起きた時の再ハッシュ関数　hash値ではなく,元の数に＋２していく、

# include <stdio.h>
#define SIZE 9

int hashkey(int key){
	return key % SIZE;
}

int rehash(int key, int table[]){
	if (table[hashkey(key+2)] != 0){
		return rehash(key+2, table);
	}
	else
		return hashkey(key+2);
}

void add_table(int a[], int table[]){
	for (int i = 0; i < SIZE; i++){
		if (table[hashkey(a[i])] == 0){
			// まだデータ入ってなかったら値いれる。
			table[hashkey(a[i])] = a[i];
		}
		else
			table[rehash(a[i], table)] = a[i];
	}
}

int search_hash(int key, int a[]){
	//データセットからハッシュテーブル作成
	int table[SIZE] = {0};
	add_table(a, table);
	int count = 1;
	while (table[hashkey(key)] != key){
		count++;
		search_hash(key+2, table);
	}
	return count;
}

int main(){
	int a[9] = {15, 13, 14, 1, 7, 0, 9, 2, 3};
	int key;
	printf("Key? ");
	scanf("%d", &key);

	int count = search_hash(key, a);
	if (count == -1)
		printf("Not Found.\n");
	else
		printf("Found (Step = %d)\n", count);
	return 0;
}