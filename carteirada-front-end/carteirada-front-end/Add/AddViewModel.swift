//
//  AddViewModel.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 25/09/22.
//


import Foundation

class AddViewModel {
    var service: AddActiveService?
    var delegate: ServiceDelegate?

    init(_ service: AddActiveService? = AddActiveService(), delegate: ServiceDelegate? = nil) {
        self.service = service
        self.delegate = delegate
    }
    
    func postDataUser(email: String, active: String, date: Date, ticker: String, quantity: Int, price: Float) {
            delegate?.showLoad()
            service?.postActive(email: email, active: active, date: date, ticker: ticker, quantity: quantity, price: price, sucess: { result in
                self.delegate?.dataSucess()
                self.delegate?.removeLoad()
            }, error: { error in
                self.delegate?.dataFail(error: error)
                self.delegate?.removeLoad()
            })
        }
}
