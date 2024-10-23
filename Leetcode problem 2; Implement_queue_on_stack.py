class MyQueue:
    def __init__(self):
        self.stack_in = []   # Stack for incoming elements
        self.stack_out = []  # Stack for outgoing elements

    def push(self, x: int) -> None:
        # Push element onto the input stack
        self.stack_in.append(x)

    def pop(self) -> int:
        # Ensure the output stack has the elements to pop
        self._transfer()
        return self.stack_out.pop()

    def peek(self) -> int:
        # Ensure the output stack has the elements to peek
        self._transfer()
        return self.stack_out[-1]

    def empty(self) -> bool:
        # The queue is empty if both stacks are empty
        return not self.stack_in and not self.stack_out

    def _transfer(self) -> None:
        # Transfer elements from the input stack to the output stack
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())

# Example usage:
queue = MyQueue()
queue.push(10)
queue.push(20)
print(queue.peek())  # Returns 10
print(queue.pop())   # Returns 10
print(queue.empty()) # Returns False
