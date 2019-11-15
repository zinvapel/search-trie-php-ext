<?php

$ts = microtime(true);

$txt = <<<TXT
Пьер сидел в гостиной, где Шиншин, как с приезжим из-за границы, завел с ним скучный для Пьера политический разговор, к которому присоединились и другие. Когда заиграла музыка, Наташа вошла в гостиную и, подойдя прямо к Пьеру, смеясь глазами и краснея, сказала:
— Мама велела вас просить танцевать.
— Я боюсь спутать фигуры, — сказал Пьер, — но ежели вы хотите быть моим учителем…
И он подал свою толстую руку, низко опуская ее, тоненькой девочке.
Пока расстанавливались пары и строили музыканты, Пьер сел с своей маленькой дамой. Наташа была совершенно счастлива: она танцевала с большим, с приехавшим из-за границы. Она сидела на виду у всех и разговаривала с ним, как большая. У нее в руке был веер, который ей дала подержать одна барышня. И, приняв самую светскую позу (бог знает, где и когда она этому научилась), она, обмахиваясь веером и улыбаясь через веер, говорила с своим кавалером.
— Какова? какова? Смотрите, смотрите, — сказала старая графиня, проходя через залу и указывая на Наташу.
Наташа покраснела и засмеялась.
— Ну, что вы, мама? Ну, что вам за охота? Что ж тут удивительного.
В середине третьего экосеза зашевелились стулья в гостиной, где играли граф и Марья Дмитриевна, и большая часть почетных гостей и старички, потягиваясь после долгого сиденья и укладывая в карманы бумажники и кошельки, выходили в двери залы. Впереди шла Марья Дмитриевна с графом — оба с веселыми лицами. Граф с шутливою вежливостью, как-то по-балетному, подал округленную руку Марье Дмитриевне. Он выпрямился, и лицо его озарилось особенною молодецки-хитрою улыбкой, и, как только дотанцевали последнюю фигуру экосеза, он ударил в ладоши музыкантам и закричал на хоры, обращаясь к первой скрипке:
— Семен! Данилу Купора знаешь?
Это был любимый танец графа, танцованный им еще в молодости. (Данило Купор была собственно одна фигура англеза.)
— Смотрите на папа! — закричала на всю залу Наташа (совершенно забыв, что она танцует с большим), пригибая к коленам свою кудрявую головку и заливаясь своим звонким смехом по всей зале.
Действительно, все, что только было в зале, с улыбкою радости смотрело на веселого старичка, который рядом с своею сановитою дамой, Марьей Дмитриевной, бывшей выше его ростом, округлял руки, в такт потряхивая ими, расправлял плечи, вывертывал ноги, слегка притопывая, и все более и более распускавшеюся улыбкой на своем круглом лице приготовлял зрителей к тому, что будет. Как только заслышались веселые, вызывающие звуки Данилы Купора, похожие на развеселого трепачка, все двери залы вдруг заставились с одной стороны мужскими, с другой — женскими улыбающимися лицами дворовых, вышедших посмотреть на веселящегося барина.
— Батюшка-то наш! Орел! — проговорила громко няня из одной двери.
Граф танцевал хорошо и знал это, но его дама вовсе не умела и не хотела хорошо танцевать. Ее огромное тело стояло прямо, с опущенными вниз мощными руками (она передала ридикюль графине); только одно строгое, но красивое лицо ее танцевало. Что выражалось во всей круглой фигуре графа, у Марьи Дмитриевны выражалось лишь в более и более улыбающемся лице и вздергивающемся носе. Но зато, ежели граф, все более и более расходясь, пленял зрителей неожиданностью ловких вывертов и легких прыжков своих мягких ног, Марья Дмитриевна малейшим усердием при движении плеч или округлении рук в поворотах и прито-пываньях производила не меньшее впечатление по заслуге, которую ценил всякий при ее тучности и всегдашней суровости. Пляска оживлялась все более и более. Визави не могли ни на минуту обратить на себя внимание и даже не старались о том. Все было занято графом и Марьею Дмитриевной. Наташа дергала за рукава и платье всех присутствовавших, которые и без того не спускали глаз с танцующих, и требовала, чтобы смотрели на папеньку. Граф в промежутках танца тяжело переводил дух, махал и кричал музыкантам, чтоб они играли скорее. Скорее, скорее и скорее, лише, лише и лише развертывался граф, то на цыпочках, то на каблуках носясь вокруг Марьи Дмитриевны, и, наконец, повернув свою даму к ее месту, сделал последнее па, подняв сзади кверху свою мягкую ногу, склонив вспотевшую голову с улыбающимся лицом и округло размахнув правою рукою среди грохота рукоплесканий и хохота, особенно Наташи. Оба танцора остановились, тяжело переводя дыхание и утираясь батистовыми платками.
— Вот как в наше время танцевали, mа сheге, — сказал граф.
— Ай да Данила Купор! — тяжело и продолжительно выпуская дух и засучивая рукава, сказала Марья Дмитриевна.
TXT;

$trie = Zp_Strie\Fnt_Utf8::makeText($txt, static function (int $char) {
    return $char < 65 || ($char > 127 && $char < 161) || $char === 173;
});

$needleList = ['папа', 'граф', 'охота', 'Батюшка', 'noname'];

foreach ($needleList as $needle) {
    $localTree = $trie;

    foreach (Zp_Strie\Fnt_Utf8::toCharList($needle) as $char) {
        if ($localTree->next($char << 1) === null) {
            echo "$needle does not exist", PHP_EOL;
            continue 2;
        }

        $localTree = $localTree->next($char << 1);
    }

    echo "$needle found", PHP_EOL;
}

printf(
    "%.4f\n",
    microtime(true) - $ts
);