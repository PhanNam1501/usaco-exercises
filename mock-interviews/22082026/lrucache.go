package main

// Đề bài:
// ### Bài toán: Thiết kế LFU Cache (Least Frequently Used Cache)

// Thiết kế và cài đặt cấu trúc dữ liệu cho bộ nhớ đệm LFU Cache với dung lượng cố định là capacity.

// #### Các thao tác cần hỗ trợ:
// * Get(key): Lấy giá trị tương ứng với key nếu tồn tại trong cache, ngược lại trả về -1. Thao tác này được tính là một lượt truy cập (tăng tần suất sử dụng của key lên 1).
// * Put(key, value):
//   * Cập nhật giá trị nếu key đã tồn tại và tăng tần suất sử dụng lên 1.
//   * Nếu key chưa tồn tại, chèn mới cặp (key, value) với tần suất ban đầu là 1.
//   * Khi số lượng phần tử vượt quá capacity, loại bỏ phần tử có tần suất sử dụng thấp nhất (Least Frequently Used) trước khi chèn mới.
//   * Quy tắc giải quyết hòa (Tie-breaker): Nếu có nhiều phần tử có cùng tần suất sử dụng thấp nhất, loại bỏ phần tử ít được truy cập gần đây nhất (Least Recently Used - LRU) trong nhóm đó.

// #### Yêu cầu kỹ thuật:
// * Time Complexity: Cả hai thao tác Get và Put đều phải đạt độ phức tạp thời gian trung bình là O(1).
// * Space Complexity: O(capacity).

import "container/list"

type LRUCache struct {
	MpFreq        map[int]*list.List
	MpKV          map[string]string
	MpNode        map[string]*list.Element
	KeyFreq       map[string]int
	NumOfElements int
	MinFreq       int
	MaxElements   int
}

func NewLRUCache(maxElements int) *LRUCache {
	return &LRUCache{
		MpFreq:        make(map[int]*list.List),
		MpKV:          make(map[string]string),
		MpNode:        make(map[string]*list.Element),
		KeyFreq:       make(map[string]int),
		NumOfElements: 0,
		MinFreq:       0,
		MaxElements:   maxElements,
	}
}

func (l *LRUCache) Put(key, value string) {
	if l.MaxElements == 0 {
		return
	}

	_, ok := l.MpKV[key]
	if !ok {
		if l.NumOfElements >= l.MaxElements {
			node := l.MpFreq[l.MinFreq].Front()
			l.MpFreq[l.MinFreq].Remove(node)
			evictedKey := node.Value.(string)
			delete(l.MpKV, evictedKey)
			delete(l.MpNode, evictedKey)
			delete(l.KeyFreq, evictedKey)
			l.NumOfElements--
		}

		if l.MpFreq[1] == nil {
			l.MpFreq[1] = list.New()
		}
		node := l.MpFreq[1].PushBack(key)
		l.KeyFreq[key] = 1
		l.MpNode[key] = node
		l.MpKV[key] = value
		l.MinFreq = 1
		l.NumOfElements++
	} else {
		l.MpKV[key] = value

		freq := l.KeyFreq[key]
		l.MpFreq[freq].Remove(l.MpNode[key])
		if freq == l.MinFreq && l.MpFreq[freq].Len() == 0 {
			l.MinFreq++
		}

		freq++
		if l.MpFreq[freq] == nil {
			l.MpFreq[freq] = list.New()
		}
		l.MpNode[key] = l.MpFreq[freq].PushBack(key)
		l.KeyFreq[key] = freq
	}
}

func (l *LRUCache) Get(key string) string {
	v, ok := l.MpKV[key]
	if !ok {
		return "-1"
	} else {
		freq := l.KeyFreq[key]
		l.MpFreq[freq].Remove(l.MpNode[key])
		if freq == l.MinFreq && l.MpFreq[freq].Len() == 0 {
			l.MinFreq++
		}

		freq++
		if l.MpFreq[freq] == nil {
			l.MpFreq[freq] = list.New()
		}
		l.MpFreq[freq].PushBack(key)
		l.MpNode[key] = l.MpFreq[freq].Back()
		l.KeyFreq[key]++
		return v
	}
}
