<?php
declare(strict_types=1);

namespace Zp_Strie;

class Fnt
{
    public static function makeWord(string $word): iterable {}
    public static function makeText(string $word, callable $isWordEnding): Trie {}
    public static function toCharList(string $text): iterable {}
}
