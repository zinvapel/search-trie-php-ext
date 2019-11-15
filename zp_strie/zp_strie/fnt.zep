namespace Zp_Strie;

class Fnt
{
    public static function makeWord(string! word) -> <Trie>
    {
        var ch, trie; int i;

        let trie = new Trie(0 << 1);
        var local = trie;

        for i in range(0, word->length() - 1) {
            let ch = word[i];
            let local = local->insert(ch << 1);
        }

        return trie;
    }

    public static function makeText(string! text, var isWordEnding) -> <Trie>
    {
        var ch, trie; int i;

        let trie = new Trie(0 << 1);
        var local = trie;

        for i in range(0, text->length() - 1) {
            let ch = text[i];

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
        var ch; int i; array charList;

        let charList = [];

        for i in range(0, text->length() - 1) {
            let ch = text[i];
            let charList[] = ch << 1;
        }

        return charList;
    }

    public static function toUtf8CharList(string! text)
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
