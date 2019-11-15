<?php
declare(strict_types=1);

namespace Zp_Strie;

class Trie
{
    public function __construct(int $char, Trie $parent = null) {}
    public function toChar(): int {}
    public function toLeaf(): Trie {}
    public function insert(int $char): Trie {}
    public function next(int $char): ?Trie {}
    public function parent(): Trie {}
}
