namespace Zp_Strie;

class Fnt_Utf8
{
    private static map = [
        65: 97,
        66: 98,
        67: 99,
        68: 100,
        69: 101,
        70: 102,
        71: 103,
        72: 104,
        73: 105,
        74: 106,
        75: 107,
        76: 108,
        77: 109,
        78: 110,
        79: 111,
        80: 112,
        81: 113,
        82: 114,
        83: 115,
        84: 116,
        85: 117,
        86: 118,
        87: 119,
        88: 120,
        89: 121,
        90: 122,
        53392: 53424,
        53393: 53425,
        53394: 53426,
        53395: 53427,
        53396: 53428,
        53397: 53429,
        53377: 53649,
        53398: 53430,
        53399: 53431,
        53400: 53432,
        53401: 53433,
        53402: 53434,
        53403: 53435,
        53404: 53436,
        53405: 53437,
        53406: 53438,
        53407: 53439,
        53408: 53632,
        53409: 53633,
        53410: 53634,
        53411: 53635,
        53412: 53636,
        53413: 53637,
        53414: 53638,
        53415: 53639,
        53416: 53640,
        53417: 53641,
        53418: 53642,
        53419: 53643,
        53420: 53644,
        53421: 53645,
        53422: 53646,
        53423: 53647
    ];

    public static function makeWord(string! word, bool ignoreCase = false) -> <Trie>
    {
        var ch, trie;

        let trie = new Trie(0 << 1);
        var local = trie;

        for ch in self::toCharList(word, ignoreCase) {
            let local = local->insert(ch << 1);
        }

        return trie;
    }

    public static function makeText(string! text, var isWordEnding, bool ignoreCase = false) -> <Trie>
    {
        var ch, trie;

        let trie = new Trie(0 << 1);
        var local = trie;

        for ch in self::toCharList(text, ignoreCase) {
            if {isWordEnding}(ch, local) {
                local->toLeaf();

                let local = trie;
            } else {
                let local = local->insert(ch << 1);
            }
        }

        return trie;
    }

    public static function toCharList(string! text, bool ignoreCase = false)
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
                if ignoreCase {
                    let charList[] = self::trans(utf8Ch);
                } else {
                    let charList[] = utf8Ch;
                }
            }
        }

        return charList;
    }

    private static function trans(int ch) -> int
    {
        if isset self::map[ch] {
            return self::map[ch];
        }

        return ch;
    }
}
