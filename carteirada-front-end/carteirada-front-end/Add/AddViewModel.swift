//
//  AddViewModel.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import Foundation

class AddViewModel {
    public func setupActives() -> [actives] {
        return [actives(image: "fiis", whatKind: "Fii's"),
                actives(image: "acoes", whatKind: "Ações"),
                actives(image: "cripto", whatKind: "Criptoativos"),
                actives(image: "rendafixa", whatKind: "Renda fixa")]
    }
}
