class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_strs  = ""
        for s in strs:
            encoded_str = ""
            for ch in s:
                encoded_str += f"{ord(ch)}#"
            encoded_strs += f"{encoded_str}*"

        #print(encoded_strs)
        return encoded_strs



    def decode(self, s: str) -> List[str]:
        words_collection = []
        decoded_words = []

        curr_string = ""
        for ch in s:
            if ch == "*":
                words_collection.append(curr_string)
                curr_string = ""
                continue
            curr_string += ch
        
        for word in words_collection:
            curr_word = ""
            last_char_idx = 0
            for i in range(len(word)):
                if word[i] == '#':
                    curr_word += chr(int(word[last_char_idx:i]))
                    last_char_idx = i + 1
            decoded_words.append(curr_word)

        return decoded_words
