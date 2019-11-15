namespace Zp_Strie;

class Trie
{
    private _char;
    private children = [];
    private parent;

    public function __construct(int _char, parent = null)
    {
        let this->_char = _char;
        let this->parent = <Trie> (empty parent ? this : parent);
    }

    public function toChar() -> int
    {
        return this->_char;
    }

    public function toLeaf() -> <Trie>
    {
        let this->_char = this->_char | 1;

        return this;
    }

    public function insert(int _char) -> <Trie>
    {
        if isset this->children[_char >> 1] {
            if (_char & 1) {
                this->children[_char >> 1]->toLeaf();
            }
        } else {
            let this->children[_char >> 1] = new Trie(_char, this);
        }

        return this->children[_char >> 1];
    }

    public function next(int _char) -> <Trie> | null
    {
        if isset this->children[_char >> 1] {
            return this->children[_char >> 1];
        }

        return null;
    }

    public function parent() -> <Trie>
    {
        return this->parent;
    }
}
