encodes = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def decode_num(nums, dec='', results=None):
    if results is None:
        results = []
    n = len(nums)
    if n == 0:
        results.append(dec)
        return
    decode_num(nums[1:], dec+encodes[int(nums[0])-1], results)
    if n > 1 and int(nums[:2]) <= 26:
        decode_num(nums[2:], dec + encodes[int(nums[:2]) - 1], results)
    return results

if __name__ == "__main__":
    print(decode_num('12345'))
    print(decode_num('226'))

