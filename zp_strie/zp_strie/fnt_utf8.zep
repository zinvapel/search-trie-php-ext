namespace Zp_Strie;

class Fnt_Utf8
{
    public static function makeWord(string! word) -> <Trie>
    {
        var ch, trie;

        let trie = new Trie(0 << 1);
        var local = trie;

        for ch in self::toCharList(word) {
            let local = local->insert(ch << 1);
        }

        return trie;
    }

    public static function makeText(string! text, var isWordEnding) -> <Trie>
    {
        var ch, trie;

        let trie = new Trie(0 << 1);
        var local = trie;

        for ch in self::toCharList(text) {
            if {isWordEnding}(ch, local) {
                local->toLeaf();

                let local = trie;
            } else {
                let local = local->insert(ch << 1);
            }
        }

        return trie;
    }

    public static function toCharList(string! text)
    {
        int i, ch, utf8Ch, octetSize, cnt, zChar, code;
        array charList;

        let charList = [];

        let octetSize = 0;
        let utf8Ch = 0;

        for i in range(0, text->length() - 1) {
            let ch = text[i];

            if octetSize === 0 {
                let utf8Ch = 0;
                let cnt = 7;

                while cnt !== 3 {
                    let zChar = ch >> cnt;
                    let code = 0;

                    for _ in range(1, 8 - cnt) {
                        let code = (code << 1) | 1;
                    }

                    if zChar !== code {
                        if cnt == 7 {
                            let octetSize = 8 - cnt;
                        } else {
                            let octetSize = 8 - cnt - 1;
                        }
                        break;
                    }

                    let cnt = cnt - 1;
                }
            }

            let utf8Ch = (utf8Ch << (octetSize * 8)) | ch;
            let octetSize = octetSize - 1;

            if octetSize === 0 {
                let charList[] = utf8Ch;
            }
        }

        return charList;
    }
}
