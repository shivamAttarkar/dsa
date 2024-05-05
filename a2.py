hashTable = []
hashTableSize = 5

def hashFunction(key):
    global hashTableSize
    return key%hashTableSize

def createBucket(key, value, chain=-1):
    return {
        'key':key,
        'value':value,
        'chain':chain
    }

def display():
    for i in range(0, hashTableSize):
        if hashTable[i]!=None:
            print(f'index: {i}, key: {hashTable[i]["key"]}, value: {hashTable[i]["value"]}, chain: {hashTable[i]["chain"]}')
        else:
            print(f'index: {i}, None')

def insert(key, value):
    hash = hashFunction(key)
    if(hashTable[hash]==None):
        hashTable[hash] = createBucket(key, value)
    else:
        i = hash+1
        while hashTable[i]!=None and i != hash:
            i = (i+1)%hashTableSize
        if hashTable[i]==None:
            hashTable[hash]["chain"] = i
            hashTable[i] = createBucket(key, value)
        else:
            print("Overflow")

def find(key):
    hash = hashFunction(key)
    if(hashTable[hash]==None):
        print("Record not found")
    else:
        i = hash
        while hashTable[i]["key"]!=key and i!=-1:
            i = hashTable[i]['chain']
        if i==-1:
            print("Record Not Found")
        else:
            print("Record Found")

def main():
    global hashTableSize
    for i in range(0, hashTableSize):
        hashTable.append(None)
    insert(10, 20)
    insert(11, 30)
    insert(20, 40)
    display()
    find(20)
    

main()