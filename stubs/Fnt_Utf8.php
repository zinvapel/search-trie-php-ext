<?php
declare(strict_types=1);

namespace Zp_Strie;

class Fnt_Utf8
{
    public static function makeWord(string $word, $ignoreCase = false): iterable {}
    public static function makeText(string $word, callable $isWordEnding, $ignoreCase = false): Trie {}
    public static function toCharList(string $text, bool $ignoreCase = false): iterable {}
}
