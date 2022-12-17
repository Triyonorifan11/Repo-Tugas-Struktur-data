class Heap {
    constructor() {
        this.dataHeap = []
    }

    getParentIndex(i) {
        return Math.floor((i - 1) / 2)
    }

    getLeftChildIndex(i) {
        return i * 2 + 1;
    }

    getRightChildIndex(i) {
        return i * 2 + 2
    }

    swap(first, second) {
        const temp = this.dataHeap[first]
        this.dataHeap[first] = this.dataHeap[second]
        this.dataHeap[second] = temp
    }

    pushHeap(key) {
        this.dataHeap[this.dataHeap.length] = key;
        this.heapifyUp()
    }

    heapifyUp() {
        let currentIndex = this.dataHeap.length - 1;

        while (this.dataHeap[currentIndex] > this.dataHeap[this.getParentIndex(currentIndex)]) {
            this.swap(currentIndex, this.getParentIndex(currentIndex))

            currentIndex = this.getParentIndex(currentIndex)
        }
    }

    poll() {
        const maxValue = this.dataHeap[0];
        this.dataHeap[0] = this.dataHeap[this.dataHeap.length - 1]
        this.dataHeap.length--;
        this.heapIfDown()

        return maxValue
    }

    heapIfDown() {
        let currentIndex = 0

        while (this.dataHeap[this.getLeftChildIndex(currentIndex)] != undefined) {
            let childTerbesar = this.getLeftChildIndex(currentIndex)

            if (this.dataHeap[this.getRightChildIndex(currentIndex)] != undefined && this.dataHeap[this.getRightChildIndex(currentIndex)] > this.dataHeap[this.getLeftChildIndex(currentIndex)]) {
                childTerbesar = this.getRightChildIndex(currentIndex)
            }

            if (this.dataHeap[currentIndex] < this.dataHeap[childTerbesar]) {
                this.swap(currentIndex, childTerbesar)
                currentIndex = childTerbesar
            } else {
                return
            }
        }
    }
}

const heaptes = new Heap()
console.log(heaptes)
heaptes.pushHeap(7)
heaptes.pushHeap(3)
heaptes.pushHeap(4)
heaptes.pushHeap(1)
heaptes.pushHeap(2)
heaptes.pushHeap(6)
heaptes.pushHeap(5)
heaptes.pushHeap(8)

console.log(heaptes.dataHeap.join(','))

let heapdwonTest = []
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())
heapdwonTest.push(heaptes.poll())


console.log('Binary Heap item:', heapdwonTest)
console.log(heaptes.dataHeap.join(','))

